#include <stdio.h>
#include <string.h>

int main()
{
    char name[101];

    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int sameword = 0;
    // printf("%lu\n", strlen(name));
    for (int i = 0; i < strlen(name); i++)
    {
        for (int k = i + 1; k < strlen(name); k++)
        {
            if (name[k] == '-')
            {
                continue;
            }

            if (name[i] == name[k])
            {
                sameword++;
                name[k] = '-';
            }
        }
    }

    // printf("%d\n", sameword);

    if ((strlen(name) - sameword) % 2 == 0)
    {
        printf("CHAT WITH HER!\n");
    }
    else
    {
        printf("IGNORE HIM!\n");
    }
}