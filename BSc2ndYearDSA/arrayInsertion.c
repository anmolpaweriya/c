#include <stdio.h>
#define pf printf

void traverse(float arr[], int len)
{
    int i;
    pf("\nIndex\t|\tvalue");
    for (i = 0; i < len; i++)
    {
        pf("\n  %d\t|\t%.2f", i, arr[i]);
    }
}

void insert(float arr[], int len, int index, float element)
{
    int i;
    for (i = len; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
}
int main()
{
    float arr[69], value; // last index of this array is 69
    int len, i, index;

    pf("Enter length of Array :-) ");
    scanf("%d", &len); // taking length of array to user

    for (i = 0; i < len; i++)
    {
        pf("Enter element %d :-) ", i + 1);
        scanf("%f", &arr[i]);
    }
    traverse(arr, len); // function to print all elements of given array

    pf("\n\nEnter Index where you want to insert Element :-) ");
    scanf("%d", &index);
    pf("Enter value to insert :-) ");
    scanf("%f", &value);

    insert(arr, len, index, value); // function to insert given value to given index in an array
    len++;
    traverse(arr, len); // function to print all elements of given array

    return 0;
}
