#include <stdio.h>
#define max 69

/*






WAP to demonstrate Lagrange's interpolation folmula





*/

int main()
{

    float arrx[max], arry[max], num, den, x, y = 0;
    int i = 0, j, n;

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







    apply formula

    */
    for (i = 0; i < n; i++)
    {
        num = den = 1;

        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            num *= x - arrx[j];
            den *= arrx[i] - arrx[j];
        }

        y += (num / den) * arry[i];
    }

    printf("\n\n Answer : %f", y);

    return 0;
}
