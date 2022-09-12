// Algorithm reference:
// https://en.wikipedia.org/wiki/Fisher–Yates_shuffle

#include <stdlib.h>

int GenerateRandomNumber(int, int);
void Swap(int, int, int);

void Shuffle(int*, int);


int GenerateRandomNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

void Swap(int vector[], int index1, int index2)
{
    int aux;
    
    aux = vector[index1];
    vector[index1] = vector[index2];
    vector[index2] = aux;
}

void Shuffle(int vector[], int size)
{
    int i, j;
    
    for (i = 0; i < size - 2; i++)
    {
        j = GenerateRandomNumber(i, size - 1);
        Swap(vector, i, j);
    }
}