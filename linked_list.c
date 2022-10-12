#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define dt int

typedef struct ap
{
    dt value;
    struct ap *next;
} ap_dt;

dt temp_value;
ap_dt *temp_ll, *top = NULL;

void push()
{
    temp_ll = (ap_dt *)malloc(sizeof(ap_dt));

    pf("\n\nEnter value to push :-) ");
    scanf("%d", &temp_ll->value);
    temp_ll->next = top;
    top = temp_ll;
}

dt pop()
{
    temp_value = top->value;
    temp_ll = top->next;
    free(top);
    top = temp_ll;
    return temp_value;
}

int main()
{
    int c;

    while (0 == 0)
    {

        pf("\n\nchoose a operation ");
        pf("\n\t 1.) push Element");
        pf("\n\t 2.) pop Element");
        pf("\n\t 3.) Exit");
        pf("\n\n Enter your choice :-) ");
        scanf("%d", &c);

        if (c == 1)
        {
            // push
            push();
        }

        else if (c == 2)
        {
            // pop
            pf("\n\nPoped value is %d", pop());
        }
        else
        {
            break;
        }

        pf("\n\n\n\tLinked list :-) \n\n");
        while (temp_ll != NULL)
        {
            pf("\n%d", temp_ll->value);
            temp_ll = temp_ll->next;
        }
    }
    return 0;
}