#include "matrix.h"

#define M1_ROWS 2
#define M1_COLS 2

#define M2_ROWS 2
#define M2_COLS 3

main()
{
    int matrix1[M1_ROWS][M1_COLS] = {{1, 2},
                                     {2, 0}};

    int matrix2[M2_ROWS][M2_COLS] = {{0, 2, 1},
                                     {1, 2, 1}};

    int matrixMultiply[M1_ROWS][M2_COLS] = {0};
    bool resMultiply = false;

    printf("MATRIX 1\n");
    MatrixPrint(M1_ROWS, M1_COLS, matrix1);
    printf("===============\n");

    printf("MATRIX 2\n");
    MatrixPrint(M1_ROWS, M1_COLS, matrix2);
    printf("===============\n");

    MatrixPrint(M1_ROWS, M2_COLS, matrixMultiply);
    printf("===============\n");

    resMultiply = MatrixMultiply(M1_ROWS, M2_COLS, matrixMultiply, 
                                 M1_ROWS, M1_COLS, matrix1, 
                                 M2_ROWS, M2_COLS, matrix2);

    if (resMultiply)
    {
        MatrixPrint(M1_ROWS, M2_COLS, matrixMultiply);
        printf("===============\n");
    }

    if (MatrixIsIdentity(M1_ROWS, M1_COLS, matrix1))
    {
        printf("MATRIZ 1 EH IDENTIDADE!!\n");
        printf("===============\n");
    }

    else
    {
        printf("MATRIZ 1 NAO EH IDENTIDADE!!\n");
        printf("===============\n");
    }
}