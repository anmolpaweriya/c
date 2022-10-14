#include <stdio.h>
#define pf printf

int numb = 0, ap[69];

int main()
{
    int temp;

start:
    pf("\n--------------------------------------");

    pf("\n\nchoose an operation ------->");
    pf("\n\t1.) push Element");
    pf("\n\t2.) pop Element");
    pf("\n\t3.) exit");
    pf("\n\n enter a choice :-) ");

    scanf("%d", &temp);

    pf("--------------------------------------");

    switch (temp)
    {
    case 1:
        if (numb < 69)
        {
            pf("\n\n Enter element to push :-) ");
            scanf("%d", &ap[numb++]);
        }
        else
        {
            pf("\n\n\nstack is full");
        }
        goto start;
    case 2:
        if (numb > 0)
        {
            pf("\n\n Poped Element is %d\n", ap[--numb]);
        }
        else
        {
            pf("\n\n stack is empty\n");
        }

        goto start;
    case 3:
        goto end;
    default:
        pf("\n\n\n\n\nInvalid Input \n\n");
        goto start;
    }

end:

    return 0;
}