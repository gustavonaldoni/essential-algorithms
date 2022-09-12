#include <stdlib.h>
#include <stdbool.h>

bool RandomProbabilityManipulation(int);

bool RandomProbabilityManipulation(int percentage)
{
    int n;
    
    srand(time(NULL));
    n = (rand() % 100) + 1;
    
    return n <= percentage;
}