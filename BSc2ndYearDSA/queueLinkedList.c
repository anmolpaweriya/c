#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} ll;

ll *createNode(int value)
{
    ll *temp = (ll *)malloc(sizeof(ll));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

int main()
{
    int value;
    ll *top = NULL, *temp, *lastPtr;

start:
    printf("\n\n\nChoose an operation ----------->");
    printf("\n\t1. insert Element");
    printf("\n\t2. delete Element");
    printf("\n\t3. Exit");
    printf("\n\nEnter Your Choice :-) ");
    scanf("%d", &value);
    switch (value)
    {
    case 1:
        // insert
        printf("\n\nEnter Value to Insert :-) ");
        scanf("%d", &value);
        if (top == NULL)
        {
            top = createNode(value);
            lastPtr = top;
        }
        else
        {
            lastPtr->next = createNode(value);
            lastPtr = lastPtr->next;
        }
        break;
    case 2:
        // delete
        if (top != NULL)
        {
            temp = top;
            top = top->next;
            printf("\n\nDeleted value is %d", temp->value);
            free(temp);
        }
        else
        {
            printf("\n\n---------[ Queue UnderFlow ]-------------------");
        }
        break;
    case 3:
        goto end;
        break;
    }
    goto start;
end:
    return 0;
}
