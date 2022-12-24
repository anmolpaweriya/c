#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;         // value store at node
    struct list *next; // pointer to store location of next node
} ll;

ll *createNode(int value)
{
    ll *temp = (ll *)malloc(sizeof(ll));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void traverseLL(ll *top)
{
    ll *temp = top;
    printf("\n\nLinked List --------->");

    while (temp != NULL)
    {
        printf("\n  %d", temp->value);
        temp = temp->next;
    }
}

int main()
{
    ll *top = NULL;

    int len, i, value;
    ll *temp;
    printf("Enter Length of Linked List :-) ");
    scanf("%d", &len);

    // temp = top;
    for (i = 0; i < len; i++)
    {
        printf("Enter value of Element %d :-) ", i + 1);
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

    traverseLL(top); // function to print all value stored in linked list
    return 0;
}
