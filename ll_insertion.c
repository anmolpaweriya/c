#include <stdio.h>
#include <stdlib.h>
#define pf printf

typedef struct ll
{
    int value;
    struct ll *next;
} ap;

ap *top = NULL, *temp, *temp2;

int main()
{
    int c, i;
start:
    pf("\n----------------------------\n");
    pf("\nChoose an operation");
    pf("\n\t1.) insert in Beginning");
    pf("\n\t2.) insert in Middle");
    pf("\n\t3.) insert in Last");
    pf("\n\t4.) exit");
    pf("\n\nEnter your choice :-)  ");

    scanf("%d", &c);

    switch (c)
    {
    case 1:
        temp = (ap *)malloc(sizeof(ap));
        pf("Enter value to insert in Beginning of list :-) ");
        scanf("%d", &temp->value);

        temp->next = top;
        top = temp;
        break;

    case 2:
        temp = top;
        pf("Enter index of list where you have to insert element  :-) ");
        scanf("%d", &c);
        for (i = 1; i < c; i++)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp = (ap *)malloc(sizeof(ap));
        pf("\nEnter value to insert to %d index of list :-) ", c);
        scanf("%d", &temp->value);
        temp->next = temp2->next;
        temp2->next = temp;
        break;
    case 3:
        temp = top;
        while (temp != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp = (ap *)malloc(sizeof(ap));
        pf("Enter value to insert to End of list :-) ");
        scanf("%d", &temp->value);
        temp->next = temp2->next;
        temp2->next = temp;
        break;

    case 4:
        goto end;
    default:
        pf("\n\n\nInvalid Input");
        goto start;
        break;
    }

    pf("\n----------------------------\n");

    pf("\n\n\t Linked List ------------>\n");

    temp = top;

    while (temp != NULL)
    {
        pf("\n %d", temp->value);
        temp = temp->next;
    }

    goto start;
end:
    return 0;
}