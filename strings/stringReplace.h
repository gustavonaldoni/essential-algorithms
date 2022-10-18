#include <string.h>

void StringReplace(char* originalString, char* word, char* changedWord)
{
    int i, j;
    int found;
    
    found = 0;
    
    for (i = 0; i < strlen(originalString); i++)
    {
        if (originalString[i] == word[0])
        {
            for (j = 0; j < strlen(word); j++)
            {
                if (originalString[i + j] == word[j])
                    found++;
                    
                else
                    found = 0;
            }
            
            if (found == strlen(word))
            {
                for (j = 0; j < strlen(word); j++)
                {
                    originalString[i + j] = changedWord[j];
                }
            }
        }
    }
}