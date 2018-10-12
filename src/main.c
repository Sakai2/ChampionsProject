#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "changeColors.h"
#include "detectBlockText.h"
#include "neuralNetwork.h"
#include "detectLetters.h"

int main(int argc, char *argv[])
{
	/*
	Matrix c = aleaMatrix(5, 3);
	printMatrix(c);
	printf("\n\n\n\n");
	//Matrix d = aleaMatrix(5, 10);
	Matrix d = giveMatrixDiag(3, 3);
	printMatrix(d);
	printf("\n\n\n\n");
	Matrix e = multMatrix(c, d);
	printMatrix(e);
	*/
	printf("Hello");

	//system("PAUSE");
	return 0;

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



