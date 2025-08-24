#include <stdio.h>
#include <math.h>

int Equation(double x1, double x1_ref)
{
    const double acceptable_value = 0.0001;
    if (fabs(x1 - x1_ref) < acceptable_value) {
        return 1;
    } else {
        return 0;
    }
}

int Swap(double* x1, double* x2)
{
double w = 0;
w = *x1;
*x1 = *x2;
*x2 = w;
return 0;
}

