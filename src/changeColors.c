#include "changeColors.h"
#include "matrix.h"
#include <SDL2/SDL.h>
//reset && gcc -c -Wall -Wextra -0 OCR_img_ope OCR_img_ope.c `sdl-config --cflags --libs`
/*
int mn (int argc, char *argv[])
{

	//variables
	SDL_Surface* downloadBMP;
	//const char BMP_path;
	char* BMP_Path2 = "premiere.bmp";
	
	//chargement de l'image
	printf("Entrez le chemin de l'image :\n");
	//scanf("%s", &BMP_path);
	downloadBMP = SDL_LoadBMP(BMP_Path2);

	//a faire avant chaque modif de la surface
	SDL_LockSurface(downloadBMP);

	//changer en niveau de gris le BMP
	NiveauGris(downloadBMP);

	//apres modification de la surface
	SDL_UnlockSurface(downloadBMP);
	SDL_SaveBMP(downloadBMP, "test.bmp");
	
	//a faire avant chaque modif de la surface
	SDL_LockSurface(downloadBMP);

	//changer en niveau de gris le BMP
	BlackAndWhite(downloadBMP);

	//apres modification de la surface
	SDL_UnlockSurface(downloadBMP);
	SDL_SaveBMP(downloadBMP, "noir.bmp");


	//a laisser a la fin pour supprimer l'epace allouer pour la surface
	SDL_FreeSurface(downloadBMP);

	return 0;
}
*/
/*
Matrix bmpToMatrix(SDL_Surface *downloadBMP)
{
	Uint32 pixel;
	int w = downloadBMP->w;
	int h = downloadBMP->h;
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 luminance;
	SDL_PixelFormat *formatBMP;

	Matrix mat = ConsrtuctMatrix();
	initMatrix(mat);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			pixel = getpixel(downloadBMP, j, i);
			SDL_GetRGB(pixel, downloadBMP->format, &r, &g, &b);
			if (r > 127)
			{
				mat.mat[i, j] = 1;
			}
			else
			{
				mat.mat[i, j] = 0;
			}
		}
	}
	return mat;
}
*/
void NiveauGris(SDL_Surface *downloadBMP)
{
	Uint32 pixel;
	int w = downloadBMP->w;
	int h = downloadBMP->h;
	Uint8 r;
    Uint8 g;
	Uint8 b;
	Uint8 luminance;
	SDL_PixelFormat *formatBMP;

	formatBMP = downloadBMP->format;

	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			pixel = getpixel(downloadBMP, j, i);
			SDL_GetRGB(pixel, downloadBMP->format, &r, &g, &b);
			luminance = 0.299*r + 0.587*g + 0.114*b;
			pixel = SDL_MapRGB(formatBMP, luminance, luminance, luminance);
			putpixel(downloadBMP, j, i, pixel);

		}
	}

}

void BlackAndWhite(SDL_Surface *downloadBMP)
{
	Uint32 pixel;
	int w = downloadBMP->w;
	int h = downloadBMP->h;
	Uint8 r;
    Uint8 g;
	Uint8 b;
	SDL_PixelFormat *formatBMP;

	formatBMP = downloadBMP->format;

	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			pixel = getpixel(downloadBMP, j, i);
			SDL_GetRGB(pixel, downloadBMP -> format, &r, &g, &b);
			if (r > 127)
				{
					r = 255;
				}
			else
			{
					r = 0;
			}
			pixel = SDL_MapRGB(formatBMP, r, r, r);
			putpixel(downloadBMP, j, i, pixel);
		}
	}	
}

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

/*
 * Set the pixel at (x, y) to the given value
 * NOTE: The surface must be locked before calling this!
 */
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

