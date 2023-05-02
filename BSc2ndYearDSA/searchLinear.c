#include <stdio.h>
#include <stdbool.h>

void traverse(int arr[], int len)
{
    int i;
    printf("\nindex\t|\tvalue");
    for (i = 0; i < len; i++)
    {
        printf("\n  %d\t|\t  %d", i, arr[i]);
    }
}

int linerSearch(int arr[], int len, int element)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[69], len = 0, i, value;

    printf("Enter length of array :-) ");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("Enter element %d :-) ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n\nArray --------->");
    traverse(arr, len); // function to show array elements

    printf("\n\nEnter Value to Search :-) ");
    scanf("%d", &value);
    i = linerSearch(arr, len, value); // index
    if (i >= 0)
    {
        printf("\n\nElement found at Index %d", i);
    }
    else
    {
        printf("\n\nElement Not Found");
    }
}
