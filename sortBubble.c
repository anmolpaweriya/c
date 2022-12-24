#include <stdio.h>

void traverse(int arr[], int len)
{
    int i;
    printf("\nindex\t|\tvalue");
    for (i = 0; i < len; i++)
    {
        printf("\n  %d\t|\t  %d", i, arr[i]);
    }
}

/*
in bubble sort
    we compare 2 adjacent elements
*/

void bubbleSort(int arr[], int len)
{
    int i, j;

    for (i = len - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[69], len = 0, i;

    printf("Enter length of array :-) ");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("Enter element %d :-) ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\n\nUnsorted Array --------->");
    traverse(arr, len); // function to show array elements

    bubbleSort(arr, len); // function to sort array with bubble sort

    printf("\n\nSorted Array --------->");
    traverse(arr, len); // function to show array elements
}
