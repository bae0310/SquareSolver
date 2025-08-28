#include <stdio.h>
#include <math.h>

#include <assert.h>
#include "test_func.h"
#include "math_func.h"

int Output(int Rts, double x1, double x2);

int main()
{
    double a = 0, b = 0, c = 0;

    AllTests();

    printf("Enter a, b, c: ");
    int NoRV = scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int Rts = SquareSolve(a, b, c, &x1, &x2, NoRV);

    Output(Rts, x1, x2);
    printf("COMMIT GITHUB\n");
    return 0;
}

//! @brief This function outputs lines depending on returned by SquareSolve-function value
//! @brief Contains switch-function
//!
//! @param [in]     Rts     returned value; main argument in switch-func
//! @param [in]     x1      1st root. For output
//! @param [in]     x2      2nd root. For output
//!
//! @note           This function is a way to shorten main-function
//! @return         0
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
