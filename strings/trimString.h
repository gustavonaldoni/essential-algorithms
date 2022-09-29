#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void StringCut(char *, char *, int, int);
void StringTrim(char *, char *);

void StringCut(char *string, char *result, int init, int end)
{
    int i, j;
    int resSize = end - init + 1;

    j = 0;
    for (i = 0; i < strlen(string) + 1; i++)
    {
        if (i >= init && i <= end)
        {
            result[j] = string[i];
            j++;
        }

        if (i == end + 1)
        {
            result[j] = '\0';
        }
    }
}

void StringTrim(char *string, char *result)
{
    int i;
    int init, end;

    init = 0;
    end = strlen(string) - 1;

    for (i = 0; i < strlen(string) + 1; i++)
    {
        if (string[i] == ' ')
            init++;
        else
            break;
    }

    for (i = strlen(string) - 1; i >= 0; i--)
    {
        if (string[i] == ' ')
            end--;
        else
            break;
    }

    StringCut(string, result, init, end);
}