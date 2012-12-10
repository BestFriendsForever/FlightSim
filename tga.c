/**
 * This module contains functions to read/manipulate targa files (*.tga).
 *
 * This is a very simple TGA lib. It will only load and save uncompressed 
 * images in greyscale, RGB or RGBA mode. If you want a more complete lib I 
 * suggest you take a look at Paul Groves' TGA loader. Paul's home page is at 
 *
 * http://paulyg.virtualave.net
 *
 * Just a little bit about the TGA file format.
 *
 * Header - 12 fields
 * id						unsigned char
 * colour map type			unsigned char
 * image type				unsigned char
 *		1	-	colour map image
 *		2	-	RGB(A) uncompressed
 *		3	-	greyscale uncompressed
 *		9	-	greyscale RLE (compressed)
 *		10	-	RGB(A) RLE (compressed)
 * colour map first entry	short int
 * colour map length		short int
 * map entry size			short int
 * horizontal origin		short int
 * vertical origin			short int
 * width					short int
 * height					short int
 * pixel depth				unsigned char
 *		8	-	greyscale
 *		24	-	RGB
 *		32	-	RGBA
 * image descriptor			unsigned char
 *
 * From all these fields, we only care about the image type, to check if the 
 * image is uncompressed and not color indexed, the width and height, and 
 * the pixel depth.
 *
 * Thanks to: Antonio Ramires Fernandes ajbrf@yahoo.com
 */
#define _TGA_C_

#include <stdio.h>
#include <stdlib.h>
#include "tga.h"

/*
 * Prototypes (local functions)
 */
void _tgaLoadHeader(FILE *file, tgaInfo *info);
void _tgaLoadImageData(FILE *file, tgaInfo *info);

/*
 * Function definitions
 */

/*
 * Loads the image header fields. We only keep those that matter!
 */
void _tgaLoadHeader(FILE *file, tgaInfo *info) 
{	
	unsigned char cGarbage;
	short int iGarbage;
	short int sDepth;

	fread(&cGarbage, sizeof(unsigned char), 1, file);
	fread(&cGarbage, sizeof(unsigned char), 1, file);
	
	/* Type must be 2 or 3 */
	fread(&info->type, sizeof(unsigned char), 1, file);
	
	fread(&iGarbage, sizeof(short int), 1, file);
	fread(&iGarbage, sizeof(short int), 1, file);
	fread(&cGarbage, sizeof(unsigned char), 1, file);
	fread(&iGarbage, sizeof(short int), 1, file);
	fread(&iGarbage, sizeof(short int), 1, file);
	
	fread(&info->width, sizeof(short int), 1, file);
	fread(&info->height, sizeof(short int), 1, file);
	fread(&info->pixelDepth, sizeof(unsigned char), 1, file);
	
	fread(&cGarbage, sizeof(unsigned char), 1, file);

	/* Check the format and components */
	sDepth = info->pixelDepth / 8;
	switch (sDepth) {
		case 3:
			info->format = GL_RGB;
			info->components = GL_RGB8;
			break;
		case 4:
			info->format = GL_RGBA;
			info->components = GL_RGBA8;
			break;
		case 1:
			info->format = GL_LUMINANCE;
			info->components = GL_LUMINANCE8;
			break;
	}	
}

/*
 * Loads the image pixels. You shouldn't call this function 
 * directly 
 */
void _tgaLoadImageData(FILE *file, tgaInfo *info) 
{	
	int mode,total,i;
	unsigned char aux;
	
	/* Mode equal the number of components for each pixel */
	mode = info->pixelDepth / 8;
	
	/* Total is the number of bytes we'll have to read */
	total = info->height * info->width * mode;
	
	fread(info->imageData,sizeof(unsigned char),total,file);
	
	/* Mode=3 or 4 implies that the image is RGB(A). However TGA
	 * stores it as BGR(A) so we'll have to swap R and B. */
	if (mode >= 3)
		for (i=0; i < total; i+= mode) {
			aux = info->imageData[i];
			info->imageData[i] = info->imageData[i+2];
			info->imageData[i+2] = aux;
		}
}

/*
 * This is the function to call when we want to load an image
 */
tgaInfo* tgaLoad(char *filename) 
{	
	FILE *file;
	tgaInfo *info;
	int mode,total;
	
    FILE *testFile = fopen ("Silly.txt", "w");
    fwrite ("String\n", 1, 7, testFile);
    fclose (testFile);
    
	/* Allocate memory for the info struct and check! */
	info = (tgaInfo *)malloc(sizeof(tgaInfo));
	if (info == NULL)
		return NULL;
		
	/* Open the file for reading (binary mode) */
	file = fopen(filename, "rb");
	if (file == NULL) {
		info->status = TGA_ERROR_FILE_OPEN;
		return info;
	}
	
	/* Load the header */
	_tgaLoadHeader(file,info);
	
	/* Check for errors when loading the header */
	if (ferror(file)) {
		info->status = TGA_ERROR_READING_FILE;
		fclose(file);
		return info;
	}
	
	/* Check if the image is color indexed */
	if (info->type == 1) {
		info->status = TGA_ERROR_INDEXED_COLOR;
		fclose(file);
		return info;
	}
	
	/* Check for other types (compressed images) */
	if ((info->type != 2) && (info->type !=3)) {
		info->status = TGA_ERROR_COMPRESSED_FILE;
		fclose(file);
		return info;
	}
	
	/* Mode equals the number of image components */
	mode = info->pixelDepth / 8;
	
	/* Total is the number of bytes to read */
	total = info->height * info->width * mode;
	
	/* Allocate memory for image pixels */
	info->imageData = (unsigned char *)malloc(sizeof(unsigned char) * total);
	
	/* Check to make sure we have the memory required */
	if (info->imageData == NULL) {
		info->status = TGA_ERROR_MEMORY;
		fclose(file);
		return info;
	}
	
	/* Finally load the image pixels */
	_tgaLoadImageData(file,info);
	
	/* Check for errors when reading the pixels */
	if (ferror(file)) {
		info->status = TGA_ERROR_READING_FILE;
		fclose(file);
		return info;
	}
	fclose(file);
	info->status = TGA_OK;
	return info;
}		

/*
 * Converts RGB to greyscale
 */
void tgaRGBtoGreyscale(tgaInfo *info) 
{	
	int mode, i, j;
	unsigned char *newImageData;
	
	/* If the image is already greyscale do nothing */
	if (info->pixelDepth == 8)
		return;
	
	/* Compute the number of actual components */
	mode = info->pixelDepth / 8;
	
	/* Allocate an array for the new image data */
	newImageData = (unsigned char *)malloc(sizeof(unsigned char) * 
										   info->height * info->width);
	if (newImageData == NULL) {
		return;
	}
	
	/* Convert pixels: greyscale = o.30 * R + 0.59 * G + 0.11 * B */
	for (i = 0,j = 0; j < info->width * info->height; i +=mode, j++)
		newImageData[j] =	(unsigned char)(0.30 * info->imageData[i] + 
											0.59 * info->imageData[i+1] +
											0.11 * info->imageData[i+2]);
	
	
	/* Free old image data */
	//free(info->imageData);
	
	/* Reassign pixelDepth and type according to the new image type */
	info->pixelDepth = 8;
	info->type = 3;
	
	/* Reassing imageData to the new array. */
	info->imageData = newImageData;
}

/*
 * Releases the memory used for the image
 */
void tgaDestroy(tgaInfo *info) 
{	
	if (info != NULL) {
		if (info->imageData != NULL)
			free(info->imageData);
		free(info);
	}
}

/* End of file -------------------------------------------------------------- */




