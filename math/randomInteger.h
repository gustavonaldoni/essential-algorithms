#include <stdlib.h>

int GenerateRandomNumber(int, int);

int GenerateRandomNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}