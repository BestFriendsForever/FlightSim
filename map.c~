/**
 * This module contains functions to create "maps" based on image files. The 
 * information about the map should be stored in a targa file (*.tga).
 */

#define _MAP_C_

#include <stdio.h>
#include <stdlib.h>

#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"

#include "tga.h"
#include "map.h"

/*
 * Function definitions
 */

/*
 * Creates a heightmap based on the given TARGA file. 
 * @param filename TARGA file name.
 * @param width Width of the image (output).
 * @param height Height of the image (output). 
 * @return Heightmap associated to the TARGA file (indexes from [0-255]).
 */
unsigned char** mapCreate(char *filename, int *width, int *height)
{
	unsigned char **map;
	unsigned char min = 225;
	tgaInfo *info;
	int i, j, k;
	
	/* Open/read the TARGA file */
	info = tgaLoad(filename);
	
	/* Check file... */
	if (info == NULL) {
		fprintf(stderr, "Problems in processing TGA file! (Code %d)", info->status);
		tgaDestroy(info);	
		return NULL;
	}
	
	/* Set the dimensions */
	*width = info->width;
	*height = info->height;
	
	/* Convert to grayscale */
	tgaRGBtoGreyscale(info);
	
	/* Create map */
	map = (unsigned char**)calloc(info->height, sizeof(unsigned char*));
	if (map == NULL) {
		fprintf(stderr, "Problems in creating the map.");
		tgaDestroy(info);	
		return NULL;
	}
	for (i=0; i<info->height; i++) {
		map[i] = (unsigned char*)calloc(info->width, sizeof(unsigned char));
		if (map[i] == NULL) {
			fprintf(stderr, "Problems in creating the map.");
			tgaDestroy(info);	
			mapDestroy(map, *height);
			return NULL;
		}
	}
	
	/* Copy color info */
	for (i=0, k=0; i<*height; i++) {
		for (j=0; j<*width; j++) {
			map[i][j] = info->imageData[k++];
			if (map[i][j] < min)
				min = map[i][j];
		}
	}
	for (i=0; i<*height; i++) {
		for (j=0; j<*width; j++) {
			map[i][j] -= min;
		}
	}
	
	/* Free info */
	tgaDestroy(info);
	
	/* Return the map */
	return map;
}

/*
 * Destroys the map
 */
void mapDestroy(unsigned char** map, int height)
{
	int i;
	
	/* Deallocate the memory */
	if (map == NULL)
		return;
	
	for (i=0; i<height; i++) {
		if (map[i] != NULL) 
			free(map[i]);
	}
	free(map);
}

/* End of file -------------------------------------------------------------- */




