#include <stdbool.h>
#include <stdio.h>

void MatrixZero(int r, int c, int (*matrix)[*]);
void MatrixPrint(int r, int c, int (*matrix)[*]);
void MatrixConstantMultiply(int constant, int r, int c, int (*matrix)[*]);
bool MatrixSum(int rowRes, int colRes, int (*matrixRes)[*], int rowMatrix1, int colMatrix1, int (*matrix1)[*], int rowMatrix2, int colMatrix2, int (*matrix2)[*]);
bool MatrixMultiply(int rowRes, int colRes, int (*matrixRes)[*], int rowMatrix1, int colMatrix1, int (*matrix1)[*], int rowMatrix2, int colMatrix2, int (*matrix2)[*]);
bool MatrixIsEqual(int rowMatrix1, int colMatrix1, int (*matrix1)[*], int rowMatrix2, int colMatrix2, int (*matrix2)[*]);
bool MatrixIsIdentity(int r, int c, int (*matrix)[*]);
void MatrixGetIdentity(int size, int (*matrix)[*]);
bool MatrixCopy(int rowRes, int colRes, int matrixRes[rowRes][colRes], int row, int col, int matrix[row][col]);

void MatrixZero(int r, int c, int matrix[r][c])
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void MatrixPrint(int r, int c, int matrix[r][c])
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (j != c - 1)
                printf("%d ", matrix[i][j]);

            else
                printf("%d \n", matrix[i][j]);
        }
    }
}

void MatrixConstantMultiply(int constant, int r, int c, int matrix[r][c])
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            matrix[i][j] *= constant;
        }
    }
}

bool MatrixSum(int rowRes, int colRes, int matrixRes[rowRes][colRes],
               int rowMatrix1, int colMatrix1, int matrix1[rowMatrix1][colMatrix1],
               int rowMatrix2, int colMatrix2, int matrix2[rowMatrix2][colMatrix2])
{
    int i, j;

    if (rowMatrix1 != rowMatrix2 || colMatrix1 != colMatrix2 ||
        rowRes != rowMatrix1 || rowRes != rowMatrix2 ||
        colRes != colMatrix1 || colRes != colMatrix2)
    {
        return false;
    }

    for (i = 0; i < rowRes; i++)
    {
        for (j = 0; j < colRes; j++)
        {
            matrixRes[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return true;
}

bool MatrixMultiply(int rowRes, int colRes, int matrixRes[rowRes][colRes],
                    int rowMatrix1, int colMatrix1, int matrix1[rowMatrix1][colMatrix1],
                    int rowMatrix2, int colMatrix2, int matrix2[rowMatrix2][colMatrix2])
{
    int i, j;
    int aux;

    if (colMatrix1 != rowMatrix2)
        return false;

    if (rowRes != rowMatrix1 || colRes != colMatrix2)
        return false;

    for (i = 0; i < rowRes; i++)
    {
        for (j = 0; j < colRes; j++)
        {
            matrixRes[i][j] = 0;

            for (aux = 0; aux < colMatrix1; aux++)
            {
                matrixRes[i][j] += matrix1[i][aux] * matrix2[aux][j];
            }
        }
    }

    return true;
}

bool MatrixIsEqual(int rowMatrix1, int colMatrix1, int matrix1[rowMatrix1][colMatrix1],
                   int rowMatrix2, int colMatrix2, int matrix2[rowMatrix2][colMatrix2])
{
    int i, j;

    if (rowMatrix1 != rowMatrix2 || colMatrix1 != colMatrix2)
        return false;

    for (i = 0; i < rowMatrix1; i++)
    {
        for (j = 0; j < colMatrix1; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
                return false;
        }
    }

    return true;
}

bool MatrixIsIdentity(int r, int c, int matrix[r][c])
{
    int i, j;

    if (r != c)
        return false;

    i = 0;
    j = 0;

    while (i < r)
    {
        if (matrix[i][j] != 1)
            return false;

        i++;
        j++;
    }

    return true;
}

void MatrixGetIdentity(int size, int matrix[size][size])
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
}

bool MatrixCopy(int rowRes, int colRes, int matrixRes[rowRes][colRes],
                int row, int col, int matrix[row][col])
{
    int i, j;

    if (rowRes != row || colRes != col)
        return false;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            matrixRes[i][j] = matrix[i][j];
        }
    }

    return true;
}
