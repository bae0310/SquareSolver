#include <stdio.h>
#include <math.h>
#include "functions.cpp"

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

    assert(std::isfinite (a));
    assert(std::isfinite (b));
    assert(std::isfinite (c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double d = b*b - 4*a*c, sqrt_d = sqrt(d); // todo initialize - Done // todo assert
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

int OneTest(double a, double b, double c, double SquareSolve_Resp,
            double x1_ref, double x2_ref)
{
    double x1 = 0, x2 = 0;
    int Rts = SquareSolve(a, b, c, &x1, &x2);
    if (!(Equation(x1, x1_ref) && Equation(x2, x2_ref)) && Rts == SquareSolve_Resp) {
        return 1;
    } else {
        return 0;
    }
}
int Count_Failed()
{
    int failed = 0;
    failed += OneTest(1, 5, 6, 2, -3, -2);
    failed += OneTest(1, 4, 4, 1, -2, -2);
    failed += OneTest(3, 0, 0, 1, 0, 0);
    failed += OneTest(0, 4, 0, 1, -0, -0);
    failed += OneTest(0, 0, 0, -1, 0, 0);
    printf("FAILED ATTEMPTS: %d  ---> ", failed);
    if (failed == 0) {
        printf("SUCCESS\n");
    } else {
        printf("ERROR\n");
    }
    return failed;
}




