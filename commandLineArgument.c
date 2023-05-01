// command Line Arguments in C
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    printf("%d\n", argc);
    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    printf("Anisole \n");
    return 0;
}
