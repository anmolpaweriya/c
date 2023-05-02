#include <stdio.h>
#include <math.h>

float f(float x) // function on which we'll apply bisection method
{
    return pow(x, 3) - 26;
}

int main()
{
    float x,
        diff = 2,
        upperLimit, lowerLimit;

    int i = 0, decimalPlace = 3; // correct upto how many decimal places

    printf("Enter Upper Limit = ");
    scanf("%f", &upperLimit);
    printf("\nEnter Lower Limit = ");
    scanf("%f", &lowerLimit);

    while (diff > 1)
    {
        diff = fabs(upperLimit - lowerLimit) * pow(10, decimalPlace);

        x = (upperLimit + lowerLimit) / 2;

        if (f(x) * f(upperLimit) > 0)
            upperLimit = x;

        else
            lowerLimit = x;

        printf("\n%02d iteration : %.5f", ++i, x);
        printf("\t limit = (%.5f, %.5f)", upperLimit, lowerLimit);
    }

    return 0;
}
