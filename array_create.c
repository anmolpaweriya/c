#include <stdio.h>
#define pf printf

int main()
{
    int numb, ap[69];
    pf("Enter number of elements to add :-) ");
    scanf("%d", &numb);
    for (int i = 0; i < numb; i++)
    {
        pf("Enter element (%d) :-) ", i + 1);
        scanf("%d", &ap[i]);
    }

    pf("\n\n\t index \t value");

    for (int i = 0; i < numb; i++)
    {
        pf("\n\t   %d\t   %d", i + 1, ap[i]);
    }

    // pf("\n\n\n\nPress any key to exit ...");
    // getch();
    return 0;
}