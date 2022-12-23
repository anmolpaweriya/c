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

void delete(float arr[], int len, int index)
{
    int i;
    for (i = index; i < len; i++)
    {
        arr[i] = arr[i + 1];
    }
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
    if (len > 0)
    {
        pf("\n\nEnter Index to delete Element :-) ");
        scanf("%d", &index);

        delete (arr, len, index); // function to delete value at given index in an array
        len--;
        traverse(arr, len); // function to print all elements of given array
    }
    else
    {
        pf("\n\nArray is underFlowed");
    }
    return 0;
}
