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

void selectionSort(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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

    selectionSort(arr, len); // function to sort array with selection sort

    printf("\n\nSorted Array --------->");
    traverse(arr, len); // function to show array elements
}
