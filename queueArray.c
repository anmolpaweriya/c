#include <stdio.h>

int delete(int queue[], int len)
{
    int i = queue[0], j;
    for (j = 0; j < len - 1; j++)
    {
        queue[j] = queue[j + 1];
    }
    return i;
}

int main()
{
    int queue[69], value, len = 0;

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
        if (len < 69)
        {

            printf("\n\nEnter value to insert :-) ");
            scanf("%d", &value);
            queue[len++] = value;
        }
        else
        {
            printf("\n\n---------[ Queue OverFlow ]-------------------");
        }
        break;
    case 2:
        // delete
        if (len > 0)
        {
            printf("\n\ndeleted value is %d", delete (queue, len--));
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
