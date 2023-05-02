#include <stdio.h>
#include <string.h>

char pattern[69]; // we'll  define pattern globally to access it in both functions
int len = 0;      // for the trace of length of matched pattern
void func(char a)
{
    if (pattern[len] == a)
    {
        len++;
    }
    else if (pattern[0] == a)
    {
        len = 1;
    }
    else
    {
        len = 0;
    }
}

int main()
{
    char str1[69];
    int i;
    printf("Enter String :-) ");
    scanf("%s", str1);
    printf("Enter Pattern :-) ");
    scanf("%s", pattern);
    for (i = 0; i < strlen(str1); i++)
    {
        func(str1[i]); // func to update length of pattern matched
        if (len == strlen(pattern))
        { // when complete pattern matched
            printf("\nPattern matched at %d", i - len + 1);
            break;
        }
    }
    if (i == strlen(str1))
    {
        printf("Pattern not found");
    }
    return 0;
}
