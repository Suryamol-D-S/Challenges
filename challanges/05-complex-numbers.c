#include <stdio.h>
#include <complex.h> // Library for complex numbers

// Define the complex-valued function
double complex f(double complex z) {
    return z*z + 1; // Example function: f(z) = z^2 + 1
}

// Function to calculate the complex derivative
double complex complex_derivative(double complex z, double h) {
    double complex derivative;
    
    // Use central finite difference method for numerical approximation
    derivative = (f(z + h) - f(z - h)) / (2.0 * h); // Ensure h is a double
    
    return derivative;
}

int main() {
    double complex z = 1 + 2 * I; // Example input double complex number
    double h = 0.0001; // Step size for numerical approximation

    // Calculate the complex derivative
    double complex derivative = complex_derivative(z, h);

    // Output the result
    printf("Complex derivative at z = %.2f + %.2fi is %.2f + %.2fi\n", creal(z), cimag(z), creal(derivative), cimag(derivative));

    return 0;
}
