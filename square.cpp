#include <stdio.h>
#include <math.h>

#include "tester.cpp"
int Output(int Rts, double x1, double x2);

int main()
{
    double a = 0, b = 0, c = 0;

    AllTests();

    printf("Enter a, b, c: ");
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int Rts = SquareSolve(a, b, c, &x1, &x2);

    Output(Rts, x1, x2);

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
//! @return Number of roots
//!
//----------------------------------------------------
double SquareSolve(double a, double b, double c,
                   double* x1, double* x2)
{
    if (Equality(a, 0)) {
       return Solve_linear(b, c, x1, x2); // return надо было написать
    } else {
        double d = b * b - 4 * a * c;

        if (d < 0) {
            return 0;
        }
        // d >= 0
        return Solve_not_a_linear(a, b, x1, x2, d); // return надо было написать
    }
}
//---------------------------------------
//! This function outputs lines depending on returned by SquareSolve-function value
//! Contains switch-function
//!
//! @param [in]     Rts     returned value; main argument in switch-func
//! @param [in]     x1      1st root. For output
//! @param [in]     x2      2nd root. For output
//!
//! @note           This function is a way to shorten main-function
//! @return         0
//---------------------------------------
int Output(int Rts, double x1, double x2)
{
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
