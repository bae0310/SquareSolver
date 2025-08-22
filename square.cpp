#include <stdio.h>
#include <math.h>

double SquareSolve(double a, double b, double c,
                    double* x1, double* x2)
{
    double sqrt_d = 0, d = 0; // todo initialize // todo assert
    d = b*b - 4*a*c;
    if (d < 0) {
        printf("D < 0\n");
    } else {
        sqrt_d = sqrt(d);
        if (a == 0) {
            *x1 = *x2 = (-c / b);
            printf("x1 = %p\n", x1);
            printf("%.2lg\n", *x1);
            return 1;
        } else {
            if (sqrt_d == 0) {
                *x1 = *x2 = (-b / (2*a));
                printf("%.2lg\n", *x1);
                return 1;
            } else if (sqrt_d > 0) {
                *x1 = ((-b + sqrt_d) / (2*a));
                *x2 = ((-b - sqrt_d) / (2*a));
                printf("%.2lg\t%.2lg\n", *x1, *x2);
                return 2;
            }
        }
    }
}

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    printf("Enter a, b, c:");
    scanf("%lg %lg %lg", &a, &b, &c);
    //printf("Amount of roots:");
    printf("%lg\n", SquareSolve(a, b, c, &x1, &x2));
    return 0;
}
