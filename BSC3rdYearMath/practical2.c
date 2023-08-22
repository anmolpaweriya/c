#include <stdio.h>
#define maxDiff 5

/*






WAP to demonstrate Newton-Backward interpolation folmula





*/

int main()
{

    float arrx[50],
        arry[50],
        diff[50][maxDiff],
        x, y, h, u,
        num = 1, den = 1;

    int i, j, n;


    /*




      taking all inputs


  */

    printf("Enter Length of List : ");
    scanf("%d", &n);

    printf("Enter values of x and y : \n");

    for (; i < n; i++)
        scanf("%f%f", &arrx[i], &arry[i]);

    printf("Enter value of x to get value of y : ");
    scanf("%f", &x);

    /*







         calculating forward differnce


     */
    for (; j < n - 1; j++)
        diff[j][0] = arry[j + 1] - arry[j];

    for (i = 1; i < maxDiff; i++)
        for (j = 0; j < n - i; j++)
            diff[j][i] = diff[j + 1][i - 1] - diff[j][i - 1];

    i = n - 1; // last element index

    /*






    apply formula

    */
    h = arrx[1] - arrx[0];
    u = (x - arrx[i]) / h;
    y = arry[i];

    for (j = 1; j < maxDiff; j++)
    {
        num *= u + j - 1;
        den *= j;

        y += (num / den) * diff[i - j][j - 1];
    }

    printf("\n\nAnswer : %f", y);

    return 0;
}
