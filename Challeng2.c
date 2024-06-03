// Numerical derivative for sin, cos and sqrt 

#include <stdio.h>
#include <math.h>
    
double f(double x)
{
    return sin(x);
}
double f1(double x)
{
    return cos(x);
}
double f2(double x)
{
    return sqrt(x);
}
double f(double x);
double f1(double x);
double f2(double x);
int main() {
    double x;
    printf("Enter the value : ");
    scanf("%g", &x);
    double d1 = cos(x);
    double d2 = -sin(x);
    double d3 = 1 / (2 * sqrt(x));
    printf("Derivatives : %g\n",d1);
    printf("Derivatives : %g\n",d2);
    printf("Derivatives : %g\n",d3);
    return 0;
}
