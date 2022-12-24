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
    ll *top = NULL, *temp;
    int value;
start:
    printf("\n\n\nChoose an operation ----------->");
    printf("\n\t1. push Element");
    printf("\n\t2. pop Element");
    printf("\n\t3. Exit");
    printf("\n\nEnter Your Choice :-) ");
    scanf("%d", &value);
    switch (value)
    {
    case 1:
        // push
        printf("\n\nEnter value to push :-) ");
        scanf("%d", &value);
        if (top == NULL)
        {
            top = createNode(value);
        }
        else
        {
            temp = createNode(value);
            temp->next = top;
            top = temp;
        }
        break;

    case 2:
        // pop
        if (top != NULL)
        {
            temp = top;
            top = top->next;
            printf("\n\n Poped value is %d", temp->value);
            free(temp);
        }
        else
        {
            printf("\n\n--------------[ Stack UnderFlow ]--------------");
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
