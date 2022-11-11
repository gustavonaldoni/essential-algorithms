#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *content;
} String;

String StringCreate(char *);
int StringDestroy(String *);
String StringConcat(String, String);
String StringReplace(String, String, String);

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

int StringDestroy(String *string)
{
    char *aux;

    aux = string->content;

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
    size_t lengthOriginal, lengthToReplace, lengthReplaceBy, lengthResult, i, j, d;
    String resultString;
    char *resultContent;
    int counter, foundWord;
    int firstLetterIndex, lastLetterIndex;

    resultString.content = NULL;
    resultContent = NULL;

    counter = 0;
    foundWord = 0;

    firstLetterIndex = -1;
    lastLetterIndex = -1;

    lengthToReplace = strlen(toReplace.content);
    lengthOriginal = strlen(original.content);
    lengthReplaceBy = strlen(replaceBy.content);

    lengthResult = 0;

    j = 0;

    // Verify where, at 'original', we have the string 'toReplace'
    for (i = 0; i < lengthOriginal - lengthToReplace + 1; i++)
    {
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
            lastLetterIndex = i;
            foundWord = 1;
            break;
        }
    }

    j = 0;

    if (foundWord == 1)
    {
        firstLetterIndex = lastLetterIndex - lengthToReplace + 1;

        if (lengthReplaceBy == lengthToReplace)
        {
            lengthResult = lengthOriginal + (lengthReplaceBy - lengthToReplace);

            resultContent = (char *)malloc(lengthResult);

            for (i = 0; i < lengthResult; i++)
            {
                if (i >= firstLetterIndex && i <= lastLetterIndex)
                {
                    resultContent[i] = replaceBy.content[j];
                    j += 1;
                }

                else
                    resultContent[i] = original.content[i];
            }
        }

        if (lengthReplaceBy > lengthToReplace)
        {
            d = lengthReplaceBy - lengthToReplace;
            lengthResult = lengthOriginal + d;

            resultContent = (char *)malloc(lengthResult);

            for (i = 0; i < lengthResult; i++)
            {
                if (i >= firstLetterIndex && i <= lastLetterIndex + d)
                {
                    resultContent[i] = replaceBy.content[j];
                    j += 1;
                }

                else
                {
                    if (i > lastLetterIndex)
                        resultContent[i] = original.content[i - d];

                    else if (i < firstLetterIndex)
                        resultContent[i] = original.content[i];
                }
            }
        }

        if (lengthReplaceBy < lengthToReplace)
        {
            d = lengthToReplace - lengthReplaceBy;
            lengthResult = lengthOriginal - d;

            resultContent = (char *)malloc(lengthResult);

            for (i = 0; i < lengthResult; i++)
            {
                if (i >= firstLetterIndex && i <= lastLetterIndex - d)
                {
                    resultContent[i] = replaceBy.content[j];
                    j += 1;
                }

                else
                {
                    if (i < firstLetterIndex)
                        resultContent[i] = original.content[i];

                    else
                        resultContent[i] = original.content[i + d];
                }
            }
        }

        resultContent[lengthResult] = '\0';
        resultString = StringCreate(resultContent);

        free(resultContent);
    }

    return resultString;
}
