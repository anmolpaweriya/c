#include <stdio.h>

void push(int arr[], int value, int len)
{
    arr[++len] = value;
}

int pop(int arr[], int len)
{
    return arr[len];
}
int main()
{
    int stack[69], len = -1, value, choice;
start:
    printf("\n\n\nChoose an operation ----------->");
    printf("\n\t1. push Element");
    printf("\n\t2. pop Element");
    printf("\n\t3. Exit");
    printf("\n\nEnter Your Choice :-) ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // push
        if (len < 70)
        {

            printf("\n\nEnter value to Push :-) ");
            scanf("%d", &value);
            push(stack, value, len++);
        }
        else
        {
            printf("\n\n---------[ Stack OverFlow ]-------------------");
        }
        break;

    case 2:
        // pop
        if (len >= 0)
        {
            printf("\n\nPoped value is %d", pop(stack, len--));
        }
        else
        {
            printf("\n\n---------[ Stack UnderFlow ]-------------------");
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
