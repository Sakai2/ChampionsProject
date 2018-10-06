#ifndef OCR_IMG_OPE_H
#define OCR_IMG_OPE_H

//lib a inclure
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "matrix.h"
//#include <graphics.h>

//Prototypes:
void NiveauGris(SDL_Surface *downloadBMP);
void BlackAndWhite(SDL_Surface *downloadBMP);
Uint32 getpixel(SDL_Surface *surface, int x, int y);
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
Matrix bmpToMatrix(SDL_Surface *downloadBMP);

#endif
