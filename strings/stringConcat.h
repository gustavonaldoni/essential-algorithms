#include <string.h>

bool StringConcat(char*, char*);

bool StringConcat(char* originalString, char* string)
{
    int i, j;
    
    j = 0;
    
    for (i = strlen(originalString); i < strlen(originalString) + strlen(string) + 1; i++)
    {
        originalString[i] = string[j];
        j++;
    }
    
    originalString[i + 1] = '\0';
    
    return true;
}