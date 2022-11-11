// Online C compiler to run C program online

#include <stdio.h>
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
    char *resultContent;

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
            resultContent[i] = source.content[i - lengthDestination];
    }

    resultContent[lengthResult] = '\0';

    resultString = StringCreate(resultContent);

    free(resultContent);

    return resultString;
}

String StringReplace(String original, String toReplace, String replaceBy)
{
    size_t lengthOriginal, lengthToReplace, lengthReplaceBy, lengthResultString, i, j;
    String resultString;
    char *resultContent;
    unsigned short int counter, foundWord;
    short int firstLetterIndex, lastLetterIndex;

    resultString.content = NULL;
    resultContent = NULL;

    counter = 0;
    foundWord = 0;

    firstLetterIndex = -1;
    lastLetterIndex = -1;

    lengthToReplace = strlen(toReplace.content);
    lengthOriginal = strlen(original.content);
    lengthReplaceBy = strlen(replaceBy.content);

    printf("lengthToReplace = %zu\n", lengthToReplace);
    printf("lengthOriginal = %zu\n", lengthOriginal);
    printf("lengthReplaceBy = %zu\n\n", lengthReplaceBy);

    j = 0;

    // Verify where, at 'original', we have the string 'toReplace'
    for (i = 0; i < lengthOriginal - lengthToReplace + 1; i++)
    {

        printf("counter = %d\n", counter);
        printf("original.content[%d] = %c\n", i, original.content[i]);
        printf("toReplace.content[%d] = %c\n\n", j, toReplace.content[j]);

        if (original.content[i] != toReplace.content[j])
        {
            counter = 0;
            j = 0;
            continue;
        }

        else if (original.content[i] == toReplace.content[j])
        {
            counter += 1;
            j += 1;
        }

        if (counter == lengthToReplace)
        {
            printf("counter = %d\n", counter);
            lastLetterIndex = i;
            foundWord = 1;
            break;
        }
    }

    j = 0;

    if (foundWord == 1)
    {
        firstLetterIndex = lastLetterIndex - lengthToReplace + 1;
        lengthResultString = lengthOriginal + (lengthReplaceBy - lengthToReplace);

        resultContent = (char *)malloc(lengthResultString);

        for (i = 0; i < lengthResultString; i++)
        {
            if (i >= firstLetterIndex && i <= lastLetterIndex + (lengthReplaceBy - lengthToReplace))
            {
                resultContent[i] = replaceBy.content[j];
                j += 1;
            }

            else
                resultContent[i] = original.content[i];
        }

        resultContent[lengthResultString] = '\0';
        resultString = StringCreate(resultContent);

        free(resultContent);
    }

    return resultString;
}
