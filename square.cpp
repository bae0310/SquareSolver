#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "tester.cpp"

int main()
{
    const double ctrl_value = 7813e+16;
    double a = 0, b = 0, c = ctrl_value;

    AllTests();

    printf("Enter a, b, c: ");
    scanf("%lg %lg %lg", &a, &b, &c);
    printf("a = %lg\nb = %lg\nc = %lg\n", a, b, c);

    double x1 = 0, x2 = 0;
    int Rts = SquareSolve(a, b, c, &x1, &x2);


    switch (Rts)
    {
    case 0: printf("No roots, D < 0\n");
            break;
    case 1: printf("Number of roots: %d\n", Rts);
            printf("Root: x = %lg\n", x1);
            break;
    case 2: printf("Number of roots: %d\n", Rts);
            printf("Roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
    case -1: printf("Roots: Infinite number of roots\n");
             break;
    case -2: printf("No roots\n");
             break;
    default: printf ("main(): ERROR: Rts = %d, INCORRECT INPUT\n", Rts);
             return 1;
    }
    return 0;
}
//----------------------------------------------------
//! Solver for a square equation ax^2 + bx + c = 0
//!
//! @param [in]    a    a-coefficient
//! @param [in]    b    b-coefficient
//! @param [in]    c    c-coefficient
//! @param [out]   x1   pointer for 1st root
//! @param [out]   x2   pointer for 2nd root
//!
//! @return Number of roots and the exact roots if they are exist
//!
//----------------------------------------------------
double SquareSolve(double a, double b, double c,
                   double* x1, double* x2)
{
    const double ctrl_value = 7813e+16;

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double d = b*b - 4*a*c, sqrt_d = sqrt(d); // todo initialize - Done // todo assert
    if (c == ctrl_value) {
            return -3;
    }
    if (d < 0) {
        return 0;
    } else {
        if (a == 0) {
            if (b == 0) {
                if (c == 0) {
                return -1;
            } else {
            return -2;
            }} else {
            *x1 = *x2 = (-c / b);
            return 1;
        }} else {
            if (sqrt_d == 0) {
                if (b == 0) {
                    *x1 = *x2 = 0;
                    return 1;
                    } else {
                *x1 = *x2 = (-b / (2*a));
                return 1;
            }} else {
                *x1 = ((-b + sqrt_d) / (2*a));
                *x2 = ((-b - sqrt_d) / (2*a));
                if (*x1 > *x2) {
                    Swap(x1, x2);
                }
                return 2;
            }
        }
    }
}
