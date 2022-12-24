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

if array = [23,2,69,34]

then selection sort step will be

  we take 2 pointers
    1. for value
    2. for comparision

    [23,2,69,34]  // if comparision pointer value is smaller than value pointer
     ^  ^

    then comparision pointer take one step further
    [2, 23, 69, 34]
     ^  ^
    [2, 23, 69, 34]
     ^       ^
*/

void selectionSort(int arr[], int len)
{
    int i, j;

    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j]) // swap elements if array have any smaller element than previous one
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
