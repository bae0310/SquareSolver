#include <stdio.h>
#include <math.h>
double SquareSolve(double a, double b, double c,
                    double* x1, double* x2);

int main()
{
    double a = 0, b = 0, c = 0;
    printf("Enter a, b, c: ");
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    double SquareSolver_Ans = SquareSolve(a, b, c, &x1, &x2);

    printf("Number of roots: %lg\n", SquareSolver_Ans);
    if (ans > 0) {
        printf("Roots: x1 = %lg, x2 = %lg\n", x1, x2);
    }
    return 0;
}

double SquareSolve(double a, double b, double c,
                    double* x1, double* x2)
{

    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    
    double sqrt_d = 0, d = b*b - 4*a*c; // todo initialize - Done // todo assert
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
                *x1 = *x2 = (-b / (2*a));
                return 1;
            } else if (sqrt_d > 0) {
                *x1 = ((-b + sqrt_d) / (2*a));
                *x2 = ((-b - sqrt_d) / (2*a));
                return 2;
            }
        }
    }
}



int Test_SolveSquare()
{
double x1 = 0, x2 = 0;
int nRoots = SquareSolve(1, -5, 6, &x1, &x2); // 2 3
if (!(nRoots == 2 && x1 == 2 && x2 == 3)){
    printf("FAILED: SquareSolve(1, -5, 6...) -> 2; x1 = %lg, x2 = %lg (should be x1 = 2, x2 = 3)\n", x1, x2);
}
}
