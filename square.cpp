#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "tester.cpp"

int main()
{
    double a = 0, b = 0, c = 0;
    printf("Enter a, b, c: ");
    scanf("%lg %lg %lg", &a, &b, &c);


    double x1 = 0, x2 = 0;
    int SquareSolve_Resp = SquareSolve(a, b, c, &x1, &x2);
    Count_Failed();

    switch (SquareSolve_Resp)
    {
    case 0: printf("No roots, D < 0\n");
            break;
    case 1: printf("Number of roots: %d\n", SquareSolve_Resp);
            printf("Root: x = %lg\n", x1);
            break;
    case 2: printf("Number of roots: %d\n", SquareSolve_Resp);
            printf("Roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
    case -1: printf("Roots: Infinite number of roots\n");
             break;
    case -2: printf("No roots\n");
             break;
    default: printf ("main(): ERROR: SquareSolve_Resp = %d\n", SquareSolve_Resp);
             return 1;
    }
    return 0;
}

