// Numerical derivative for sin...

#include <stdio.h>
#include <math.h>
    
double F(double x)
{
    return sin(x);
}
double numerical_derivative(double (*F)(double), double x, double h) {
    return (F(x + h) - F(x)) / h;
}

int main() {
    double x;
    double h =0.001;
    printf("Enter the value : ");
    scanf("%lf", &x);
    double derivative = numerical_derivative(F, x, h);
    printf("Derivatives : %f\n",derivative);
    return 0;
}
