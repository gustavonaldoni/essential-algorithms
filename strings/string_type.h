#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char *content;
} String;

String StringCreate(char *);
bool StringDestroy(String);

String StringCreate(char *string)
{
    String result;
    size_t length, i;
    char *content;

    length = strlen(string);
    content = (char *)malloc(length);

    for (i = 0; i < length; i++)
    {
        content[i] = string[i];
    }

    content[length] = '\0';

    result.content = content;

    return result;
}

bool StringDestroy(String string)
{
    char *aux;

    aux = string.content;

    if (aux == NULL)
        return false;

    free(aux);
    return true;
}
