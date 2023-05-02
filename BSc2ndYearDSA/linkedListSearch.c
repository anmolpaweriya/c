#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool searchLL(int value, ll *head)
{
    ll *temp = head;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    ll *top = NULL, *temp;
    int len, i, value;
    printf("Enter Length of Linked List :-) ");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("Enter Element %d :-) ", i + 1);
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

    printf("\n\nEnter value to search :-) ");
    scanf("%d", &value);

    if (searchLL(value, top))
    {
        printf("\n\nElement found in Linked List");
    }
    else
    {
        printf("\n\nElement not present in Linked List");
    }
    return 0;
}
