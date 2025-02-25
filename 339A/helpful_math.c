#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortedList(char *input, int **rectifedList, int totalNumbersize)

{
    *rectifedList = (int *)calloc(totalNumbersize, sizeof(int));

    if (*rectifedList == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] != '+')
        {
            if (i == 0)
            {
                (*rectifedList)[i] = input[i] - '0';
            }
            else
            {
                (*rectifedList)[i / 2] = input[i] - '0';
            }
        }
    }
    //Linear sorting
    for (int i = 0; i < totalNumbersize; i++)
    {
        for (int k = i + 1; k < totalNumbersize; k++)
        {
            if ((*rectifedList)[i] > (*rectifedList)[k])
            {
                int temp;

                temp = (*rectifedList)[i];
                (*rectifedList)[i] = (*rectifedList)[k];
                (*rectifedList)[k] = temp;
            }
        }
    }
}

int main()
{
    char input[102];
    int *rectifiedList;
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    int totalNumber = (strlen(input) / 2) + 1;

    sortedList(&input[0], &rectifiedList, totalNumber);

    for (int i = 0; i < totalNumber; i++)
    {
        printf("%d", rectifiedList[i]);
        if (i == (totalNumber - 1))
        {
            printf("\n");
        }
        else
        {
            printf("+");
        }
    }
    free(rectifiedList);
    return 0;
}