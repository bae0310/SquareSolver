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

int Solve_linear(double b, double c, double* x1, double* x2)
{
    if (b == 0) {
        if (c == 0) {
            return -1;
        } else {
            return -2;
        }
    }
    *x1 = *x2 = -c / b;
    return 1;
}

int Solve_not_a_linear(double a, double b, double c,
                   double* x1, double* x2)
{
double sqrt_d = sqrt(d);

    if (sqrt_d == 0) {
        if (b == 0) {
            *x1 = *x2 = 0;
        } else {
            *x1 = *x2 = -b / (2*a);
        }
        return 1;
    } else {
        *x1 = (-b + sqrt_d) / (2 * a);
        *x2 = (-b - sqrt_d) / (2 * a);
        if (*x1 > *x2) {
            Swap(x1, x2);
        }
        return 2;
    }
}

