#include <stdio.h>
#include <stdlib.h>
#define pf printf

typedef struct ap
{
    int value;
    struct ap *next;
} ll;

ll *temp, *start, *list = NULL;

int main()
{
    int c;
start:
    pf("\n\n---------------------------------------------");
    pf("\nchoose an operation -------->");
    pf("\n\t1.) insert Element");
    pf("\n\t2.) delete Element");
    pf("\n\t3.) Exit");

    pf("\n\nEnter your choice :-) ");

    scanf("%d", &c);

    pf("\n\n--------------------------------------------------");

    switch (c)
    {
    case 1: // insert operation
        temp = (ll *)malloc(sizeof(ll));
        pf("\n\nEnter value to insert in queue :-) ");
        scanf("%d", &temp->value);
        temp->next = NULL;

        if (list == NULL)
        {
            start = temp;
        }

        else
        {
            list->next = temp;
        }
        list = temp;
        break;

    case 2: // delete operatin

        if (start != NULL)
        {

            temp = start;
            start = start->next;
            pf("\nDeleted Element is %d", temp->value);
            free(temp);
        }
        else
        {
            pf("\n\n------------------Queue is Empty ----------------\n");
        }
        break;

    case 3: // exit operation
        goto end;
    default:
        pf("\n--------------Invalid Input --------------\n");
        goto start;
    }

    pf("\n\nQueue ------------->\n");
    temp = start;
    if (temp == NULL)
    {
        pf("\n\n------------------Queue is Empty ----------------\n");
    }

    while (temp != NULL)
    {
        pf("\n\t%d", temp->value);
        temp = temp->next;
    }
    goto start;

end:
    return 0;
}
