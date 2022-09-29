#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void StringCut(char*, char*, int, int);
void StringTrim(char*, char*);

void StringTrim(char* string, char* result)
{
    int i;
    int init, end;
    
    init = 0;
    end = strlen(string)-1;
    
    for(i = 0; i < strlen(string) + 1; i++)
    {
        if (string[i] == ' ')
            init++;
        else
            break;
    }
    
    for (i = strlen(string)-1; i >= 0; i--)
    {
        if(string[i] == ' ')
            end--;
        else
            break;
    }
    
    StringCut(string, result, init, end);
}