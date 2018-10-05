#ifndef DetectBlocText_h
#define DetectBlocText_h

void coloriseV(Matrix mat, int i, int jn int count);
void coloriseH(Matrix mat, int i, int j, int count);
int distanceV(Matrix mat, int i, int j, int max, Matrix Colori);
int distanceH(Matrix mat, int i, int j, int max, Matrix colori);
Matrix RlsaVertical(Matrix mat, int max);
Matrix RlsaHorizontal(Matrix mat, int max);
Matrix RlsaGlobal(Matrix mat, int max);

#endif
