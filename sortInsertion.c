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
in Insertion sort
    we treat given array into 2 diffrent array
    sorted and unsorted

    and
    step by step we take element form unsorted array and insert it in sorted array
*/

void insertionSort(int arr[], int len)
{
    int i, j;

    for (i = 1; i < len; i++) // i = length of first array partition
    {
        for (j = i; j > 0; j--) // (len - i) is length of 2nd array partition
        {
            if (arr[j - 1] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
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

    insertionSort(arr, len); // function to sort array with insertion sort

    printf("\n\nSorted Array --------->");
    traverse(arr, len); // function to show array elements
}
