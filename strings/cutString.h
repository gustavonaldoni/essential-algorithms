#include <string.h>

void StringCut(char *, char *, int, int);

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