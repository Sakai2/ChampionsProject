
typedef struct Matrix Matrix;
struct Matrix
{
	int x;
	int y;
	int* mat;// = malloc(x*y * sizeof(int);
};

void printMatrix(Matrix mat);
Matrix ConsrtuctMatrix(int x, int y);
void initMatrix(Matrix a);
Matrix sumMatrix(Matrix a, Matrix b);
Matrix subtractionMatrix(Matrix a, Matrix b);
Matrix multMatrix(Matrix a, Matrix b);
Matrix multMatrixLambda(Matrix a, int lambda);
Matrix sumMatrixLambda(Matrix a, int lambda);
Matrix subtractionMatrixLambda(Matrix a, int lambda);