#include <stdio.h>

void PrintVector(int*, int);

void PrintVector(int vector[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        if (i == size - 1)
            printf("%d\n", vector[i]);
        
        else
            printf("%d ", vector[i]);
    }
}