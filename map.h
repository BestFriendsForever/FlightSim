/**
 * This module contains functions to create "maps" based on image files. The 
 * information about the map should be stored in a targa file (*.tga).
 */
#ifndef _MAP_H_
#define _MAP_H_

/*
 * Protoypes
 */
unsigned char** mapCreate(char *filename, int *width, int *height);
void mapDestroy(unsigned char** map, int height);

/* End of file -------------------------------------------------------------- */
#endif

