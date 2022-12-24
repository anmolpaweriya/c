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

void traverse(ll *head)
{
    ll *temp = head;
    printf("\n\nPointer\t|\tvalue");
    int i = 0;
    while (temp != NULL)
    {
        printf("\n  %d\t|\t  %d", i++, temp->value);
        temp = temp->next;
    }
}

int main()
{
    int len, i, value;
    ll *top = NULL, *temp;
    printf("Enter length of Linked List :-) ");
    scanf("%d", &len);
    for (i = 0; i < len; i++)
    {
        printf("Enter element %d :-) ", i + 1);
        scanf("%d", &value);
        if (top == NULL)
        {
            top = createNode(value);
            temp = top;
        }
        else
        {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }
begin:
    printf("\n\nChoose an operation -------->");
    printf("\n\t1.)Insert at Beginning");
    printf("\n\t2.)Insert at Middle");
    printf("\n\t3.)Insert at End");
    printf("\n\nEnter Your choice :-) ");
    scanf("%d", &i);
    printf("\n\nEnter value to insert :-) ");
    scanf("%d", &value);

    switch (i)
    {
    case 1: // insertion at beginning
        temp = top;
        top = createNode(value);
        top->next = temp;
        break;
    case 2:            // insertion at middle
        traverse(top); // function to print all values of linked list
        printf("\n\nEnter pointer where to insert :-) ");
        scanf("%d", &len);
        temp = top;
        for (i = 0; i < len - 1; i++)
        {
            temp = temp->next;
        }
        ll *temp2 = temp->next;
        temp->next = createNode(value);
        temp->next->next = temp2;
        break;

    case 3: // insertion at and
        temp->next = createNode(value);
        break;
    default:
        printf("\n\n----------[ Invalid Input ]--------");
        goto begin;
    }
    traverse(top); // function to print all values of linked list

    return 0;
}
