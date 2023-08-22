#include <stdio.h>

/*




WAP to demostrate Simpson's 1/3 rule



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


        taking inputs

    */

    printf("Enter First value of x : ");
    scanf("%f", &x0);
    printf("Enter Last value of x : ");
    scanf("%f", &xn);
    printf("Enter number of sub-intervals  : ");
    scanf("%d", &n);

    /*



    calculations

    */

    h = (xn - x0) / n;
    for (; i <= n; i++)
    {
        if (i == 0 || i == n)
            y += f(x0 + i * h);
        else if (i % 2 == 0)
            y += 2 * f(x0 + i * h);
        else
            y += 4 * f(x0 + i * h);
    }

    y *= h / 3;

    /*

    show result

    */

    printf("\n\nAnswer : %f", y);

    return 0;
}
