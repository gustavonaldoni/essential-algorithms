#include <string.h>

int StringFindChar(char *, char);

int StringFindChar(char *string, char letter)
{
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == letter)
            return i;
    }

    return -1;
}