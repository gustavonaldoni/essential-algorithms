#include <stdbool.h>
#include <string.h>

bool LetterExistsInString(char*, char);

bool LetterExistsInString(char* string, char letter)
{
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == letter)
            return true;
    }

    return false;
}