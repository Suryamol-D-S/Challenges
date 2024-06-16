/*Linear Algebra
=================
.
.
.
Output : 
Vector Product: 32
Matrix-Vector Product: [14, 32]
*/
#include <stdio.h>

void vectorProduct(int *v1, int *v2, int size)
{
    int result = 0;
    for (int i = 0; i < size; i++) {
	result += v1[i] * v2[i];
    }
    printf("Vector Product: %d\n", result);
}

void matrixVectorProduct(int matrix[][3], int vector[], int result[],
			 int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
	result[i] = 0;
	for (int j = 0; j < cols; j++) {
	    result[i] += matrix[i][j] * vector[j];
	}
    }
}

int main()
{
    int v1[] = { 1, 2, 3 };
    int v2[] = { 4, 5, 6 };
    int size = sizeof(v1) / sizeof(v1[0]);
    int matrix[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
    int vector[3] = { 1, 2, 3 };
    int result[2];
    int rows = 2, cols = 3;
    vectorProduct(v1, v2, size);
    matrixVectorProduct(matrix, vector, result, rows, cols);
    printf("Matrix-Vector Product: [%d, %d]\n", result[0], result[1]);
    return 0;
}
