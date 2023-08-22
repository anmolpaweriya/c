#include <stdio.h>

/*




WAP to demostrate Trapezoidal rule



*/

// function on which we'll apply trapezoidal rule
float f(float x)
{
    return 1 / (1 + x * x);
}

int main()
{

    float x0, xn, h, y = 0;
    int i = 0, n;

    /*



        taking input


    */

    printf("Enter first value of x : ");
    scanf("%f", &x0);
    printf("Enter Last value of x : ");
    scanf("%f", &xn);

    printf("Enter number of sub-intervals : ");
    scanf("%d", &n);

    /*


    appling formula

    */

    h = (xn - x0) / n;

    for (; i <= n; i++)
    {
        y += f(x0 + i * h);
        if (i != 0 && i != n)
            y += f(x0 + i * h);
    }
    y *= h / 2;

    /*


   show  answer
    */

    printf("\n\nAnswer : %f", y);

    return 0;
}
