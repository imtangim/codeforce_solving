#include <stdio.h>
#include <string.h>

char lowAlphabet(char alphabet)
{
    if (alphabet < 97)
    {
        return alphabet + 32;
    }
    else
    {
        return alphabet;
    }
}

int result(char a, char b)
{
    if (a < b)
    {
        return -1;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char strA[102];
    fgets(strA, sizeof(strA), stdin);
    strA[strcspn(strA, "\n")] = '\0'; // Removing the newline character from the end of the string
    char strB[102];
    fgets(strB, sizeof(strB), stdin);
    strB[strcspn(strB, "\n")] = '\0'; // Removing the newline character from the end of the string

    if (strlen(strA) == strlen(strB))
    {

        for (int i = 0; i < strlen(strA); i++)
        {
            if (lowAlphabet(strA[i]) == lowAlphabet(strB[i]))
            {
                continue;
            }
            else
            {
                printf("%d\n", result(lowAlphabet(strA[i]), lowAlphabet(strB[i])));
                return 0;
            }
        }
        printf("0\n");
    }
    else
    {
        return 0;
    }

    return 0;
}