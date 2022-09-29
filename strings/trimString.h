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
    control = true;
    
    for(i = 0; i < strlen(string); i++)
    {
        if (control == true)
        {
            if (string[i] == ' ')
            {
                init += 1;
            }
        
            else
            {
                control = false;
            }
        }
        
    }
    
    for(i = strlen(string); i >= 0; i--)
    {
        if (control == true)
        {
            if (string[i] == ' ')
            {
                end -= 1;
            }
        
            else
            {
                control = false;
            }
        }
    }
    
    StringCut(string, result, init, end);
}