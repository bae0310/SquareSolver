#include <stdio.h>
#include <math.h>
#include "functions.cpp"

double SquareSolve(double a, double b, double c,
                   double* x1, double* x2);

struct TestData
{
    double a, b, c;
    double Rts;
    double x1, x2;
};

int OneTest(TestData test)
{
    double x1 = 0, x2 = 0;
    int Rts = SquareSolve(test.a, test.b, test.c, &x1, &x2);
    if (!(Equation(x1, test.x1) && Equation(x2, test.x2)) && test.Rts == Rts) {
        return 1;
    } else {
        return 0;
    }
}

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



