#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *content;
} String;

String StringCreate(char *);
int StringDestroy(String);
String StringConcat(String, String);

String StringCreate(char *string)
{
    String result;
    size_t length, i;
    char *content;

    length = strlen(string);
    content = (char *)malloc(length);

    if (content == NULL)
    {
        result.content = NULL;
        return result;
    }

    for (i = 0; i < length; i++)
    {
        content[i] = string[i];
    }

    content[length] = '\0';

    result.content = content;

    return result;
}

int StringDestroy(String string)
{
    char *aux;

    aux = string.content;

    if (aux == NULL)
        return 0;

    free(aux);
    return 1;
}

String StringConcat(String source, String destination)
{
    size_t lengthSource, lengthDestination, lengthResult, i;
    String resultString;
    char *resultContent, *auxDestination;

    lengthSource = strlen(source.content);
    lengthDestination = strlen(destination.content);
    lengthResult = lengthSource + lengthDestination;

    resultContent = (char *)malloc(lengthResult);

    if (resultContent == NULL)
        return;
    
    for (i = 0; i < lengthResult; i++)
    {
        if (i < lengthDestination)
           resultContent[i] = destination.content[i]; 
        
        else
            resultContent[i] = source.content[i-lengthDestination]; 
    }
    
    resultContent[lengthResult] = '\0';

    resultString = StringCreate(resultContent);

    return resultString;
}
