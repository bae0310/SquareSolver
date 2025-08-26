#include <stdio.h>
#include <math.h>
#include "math_func.h"
//! @brief Compares two numbers
//! @param [in]     x1      1st number for comparation
//! @param [in]     x1_ref  2nd number for comparation
//! @return 1 -- if numbers are equal; 0 -- if not
int Equality(double x1, double x1_ref)
{
    const double acceptable_value = 0.0001;
    if (fabs(x1 - x1_ref) < acceptable_value) {
        return 1;
    } else {
        return 0;
    }
}
//! @brief Swaps roots: x1, x2 = x2, x1
//! @param [in]     x1      pointer for 1st root
//! @param [in]     x2      pointer for 2nd root
//! @return 0 -- if swap is done
int Swap(double* x1, double* x2)
{
    double w = 0;
    w = *x1;
    *x1 = *x2;
    *x2 = w;
    return 0;
}
//! @brief Solver for a linear equation bx + c = 0
//! @param [in]   b    b-coefficient
//! @param [in]   c    c-coefficient
//! @param [out]  x1   pointer for 1st root
//! @param [out]  x2   pointer for 2nd root
//! @note -1 -- infinite number of roots; -2 -- no roots; 0 -- no roots; 1 -- one root;
//! @return Number of roots
//! @note -1 -- Infinite number of roots; -2 -- no roots; 1 -- one root;
int Solve_linear(double b, double c, double* x1, double* x2)
{
    if (Equality(b, 0)) {
        if (Equality(c, 0)) {
            return -1;
        } else {
            return -2;
        }
    }
    *x1 = *x2 = -c / b;
    return 1;
}
//! @brief Solver for a square equation ax^2 + bx + c = 0, if a != 0
//! @param [in]   a    a-coefficient
//! @param [in]   b    b-coefficient
//! @param [out]  x1   pointer for 1st root
//! @param [out]  x2   pointer for 2nd root
//! @param [in]   d    discriminant
//! @return Number of roots
//! @note 0 -- no roots; 1 -- one root; 2 -- two roots;
int Solve_not_a_linear(double a, double b,
                   double* x1, double* x2, double d)
{
    double sqrt_d = sqrt(d);

    if (Equality(sqrt_d, 0)) {
        if (Equality(b, 0)) {
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

