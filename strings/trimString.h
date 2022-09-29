#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void StringCut(char*, char*, int, int);
void StringTrim(char*, char*);

void StringTrim(char* string, char* result)
{
    int i;
    int init, end;
    bool control;
    
    init = 0;
    end = strlen(string);
    
    for(i = 0; i < strlen(string); i++)
    {
        printf("init = %d\n", init);
        if (string[i] == ' ')
        {
            init++;
        }
        
        else
        {
            break;
        }
        
    }
    
    for(i = strlen(string); i >= 0; i--)
    {
        printf("end = %d\n", end);
        if (string[i] == ' ')
        {
            end--;
        }
        
        else
        {
            break;
        }
        
        
    }
    
    StringCut(string, result, init, end);
}