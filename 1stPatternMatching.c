#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main()
{
    int i, j;
    bool flag;
    char str1[69], pattern[69];
    printf("Enter String :-) ");
    scanf("%s", str1);
    printf("Enter Pattern :-) ");
    scanf("%s", pattern);
    for (i = 0; i <= (strlen(str1) - strlen(pattern)); i++)
    {
        if (pattern[0] == str1[i])
        {
            flag = true;
            for (j = 0; j < strlen(pattern); j++)
            {
                if (str1[i + j] != pattern[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                printf("Pattern Matched at Index %d", i);
                break;
            }
        }
    }
    if (i > (strlen(str1) - strlen(pattern)))
    {

        printf("Pattern not found");
    }
    return 0;
}
