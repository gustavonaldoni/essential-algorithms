void MatrixPrint(int r, int c, int matrix[r][c])
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
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
        for(j = 0; j < c; j++)
        {
            matrix[i][j] *= constant;
        }
    }
}
