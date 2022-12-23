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

int main()
{
    float arr[69]; // last index of this array is 69
    int len, i;

    pf("Enter length of Array :-) ");
    scanf("%d", &len); // taking length of array to user

    for (i = 0; i < len; i++)
    {
        pf("Enter element %d :-) ", i + 1);
        scanf("%f", &arr[i]);
    }
    traverse(arr, len); // function to print all elements of given array
    return 0;
}
