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
{ // function use to print all values stored in linked list
    int i = 0;
    ll *temp = head;
    printf("\n\npointer\t|\tvalue");
    while (temp != NULL)
    {
        printf("\n  %d\t|\t  %d", i++, temp->value);
        temp = temp->next;
    }
}

void deleteLL(ll *preNode)
{
    if (preNode->next != NULL)
    {
        ll *temp = preNode->next;
        preNode->next = preNode->next->next;
        free(temp);
    }
}

int main()
{
    int len, value, i;
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

    traverse(top); // function used to print all values stored in linked List

    printf("\n\nEnter Pointer of Element to delete :-) ");
    scanf("%d", &len);
    temp = top;
    for (i = 0; i < len - 1; i++)
    {
        temp = temp->next;
    }
    deleteLL(temp); // function to delete element in linked list arrgument required is preNode of the deletion node

    printf("\n\nLinked List after Deletion ------------>");
    traverse(top); // function used to print all values stored in linked List

    return 0;
}
