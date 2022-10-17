#include <string.h>
#include <stdbool.h>

bool StringReplaceChar(char *, char, char);
bool StringReplaceCharAll(char *, char, char);

bool StringReplaceChar(char *string, char initCharacter, char endCharacter)
{   
    int i;

    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == initCharacter)
        {
            string[i] = endCharacter;
            return true;
        }
    }

    return false;
}

bool StringReplaceCharAll(char *string, char initCharacter, char endCharacter)
{
    int i, counter;

    counter = 0;

    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == initCharacter)
        {
            string[i] = endCharacter;
            counter++;
        }
    }

    return counter >= 1;
}