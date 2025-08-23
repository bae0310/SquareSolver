#include <stdio.h>
#include <math.h>
#include <assert.h>
double SquareSolve(double a, double b, double c,
                    double* x1, double* x2);
int Test_SquareSolve1();
int Test_SquareSolve2();
int Swap(double* x1, double* x2);

int main()
{
    Test_SquareSolve1();
    Test_SquareSolve2();
    double a = 0, b = 0, c = 0;
    printf("Enter a, b, c: ");
    scanf("%lg %lg %lg", &a, &b, &c);



    double x1 = 0, x2 = 0;
    double SquareSolve_Resp = SquareSolve(a, b, c, &x1, &x2);

    printf("Number of roots: %lg\n", SquareSolve_Resp);
    if (SquareSolve_Resp > 0) {
        if (SquareSolve_Resp == 1) {
            printf("Root: x = %lg\n", x1);
        } else {
            printf("Roots: x1 = %.2lg, x2 = %.2lg\n", x1, x2);
    }}
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
    // printf("a = %lg\n", a);
    // printf("b = %lg\n", b);
    // printf("c = %lg\n", c);

    assert(std::isfinite (a));
    assert(std::isfinite (b));
    assert(std::isfinite (c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    double d = b*b - 4*a*c, sqrt_d = sqrt(d); // todo initialize - Done // todo assert
    if (d < 0) {
        printf("No roots, D < 0\n");
        return 0;
    } else {
        sqrt_d = sqrt(d);
        if (a == 0) {
            if (b == 0) {
                if (c == 0) {
                printf("Infinite number of roots\n");
                return -1;
            } else {
            printf("No roots\n");
            return 0;
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
            }} else if (sqrt_d > 0) {
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



int Test_SquareSolve1()
{
double x1 = 0, x2 = 0;
int nRoots = SquareSolve(1, -5, 6, &x1, &x2); // 2 3
if (!(nRoots == 2 && x1 == 2 && x2 == 3)){
    printf("FAILED: SquareSolve(1, -5, 6...) -> 2; x1 = %lg, x2 = %lg (should be x1 = 2, x2 = 3)\n", x1, x2);
} else {
printf("Test #1 successfully completed\n");
}
}

int Test_SquareSolve2() {
double x1 = 0, x2 = 0;
int Rts = SquareSolve(0, 0, 5, &x1, &x2);
if(!(Rts == 0 && x1 == 0 && x2 == 0)) {
    printf("FAILED: SquareSolve(0, 0, 5...) -> 0; x1 = %lg, x2 = %lg (should be x1 = 0, x2 = 0)\n", x1, x2);
} else {
    printf("Test #2 successfully completed\n");
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

