#include "matrix.h"

#ifndef DetectLetters
#define DettectLetters

int countOneY(int i, int j, Matrix RLSA);
int countOneX(int i, int j, Matrix RLSA);
void applyBox(int i, int j, int countX, int countY, Matrix trueMat);
Matrix boxColors(Matrix RLSA, Matrix trueMat);

#endif
