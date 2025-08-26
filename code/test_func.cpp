#include <stdio.h>
#include <math.h>
#include "math_func.cpp"

double SquareSolve(double a, double b, double c,
                   double* x1, double* x2);
struct TestData
{
    double a, b, c;
    double Rts;
    double x1, x2;
};
//! @brief Running SquareSolve-function with certain coefficients and compares received and reference roots
//!
//! @param [in]    a    a-coefficient
//! @param [in]    b    b-coefficient
//! @param [in]    c    c-coefficient
//!
//! @param [in]    Rts   Number of reference roots
//!
//! @param [out]   x1   pointer for 1st reference root
//! @param [out]   x2   pointer for 2nd reference root
//!
//! @return             0 -- if received and reference roots are equal ; 1 -- if not
int OneTest(TestData test)
{
    double x1 = 0, x2 = 0;
    int Rts = SquareSolve(test.a, test.b, test.c, &x1, &x2);
    if (!(Equality(x1, test.x1) && Equality(x2, test.x2)) && Equality(Rts, test.Rts)) {
        return 1;
    } else {
        return 0;
    }
}

//! @brief Creates list, each ___ of the list contains values for OneTest-func.
//! @brief Runs OneTest-function several times using loop.
//! @brief Prints number of failed tests and the following lines
//!
//!
//! @return             Number of failed tests
int AllTests()
{
    int failed = 0;
    TestData global_test[6] = { {.a = 1, .b = 5, .c = 6, .Rts = 2, .x1 = -3, .x2 = -2},
                                {.a = 1, .b = 4, .c = 4, .Rts = 1, .x1 = -2, .x2 = -2},
                                {.a = 3, .b = 0, .c = 0, .Rts = 1, .x1 = 0, .x2 = 0},
                                {.a = 0, .b = 4, .c = 0, .Rts = 1, .x1 = -0, .x2 = -0},
                                {.a = 0, .b = 0, .c = 0, .Rts = -1, .x1 = 0, .x2 = 0},
                                {.a = 0, .b = 0, .c = 3, .Rts = 0, .x1 = 0, .x2 = 0} };
    int counter = sizeof(global_test) / sizeof(global_test[0]);
    for (int i = 0; i < counter; i++) {
        failed += OneTest(global_test[i]);
    }
    printf("FAILED ATTEMPTS: %d  ---> ", failed);
    if (failed == 0) {
        printf("CORRECT FORMULA\n");
    } else {
        printf("ERROR\n");
    }
    return failed;
}



