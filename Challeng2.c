// Numerical derivative for sin...

#include <stdio.h>
#include <math.h>
    
double F(double x)
{
    return sin(x);
}
double numerical_derivative(double *F(double), double x, double h) {
    return (F(x + h) - F(x)) / h;
}
double F(double x);
int main() {
    double x;
    double h =0.0001;
    printf("Enter the value : ");
    scanf("%g", &x);
    double derivative = numerical_derivative(F, x, h);
    printf("Derivatives : %g\n",cos);
    return 0;
}
