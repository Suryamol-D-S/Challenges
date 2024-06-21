/*Implement rat_print_normalized by combining rat_normalize and rat_print.
rat_normalize means Normalizes a rational number (fraction) so that its numerator and denominator have no common factors other than 1. For example, 2/4 becomes 1/2.
rat_print means Prints a rational number in the format numerator/denominator.

Output :-
Normalized form: 1/2
Original form: 2/4
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a rational number (fraction)
typedef struct {
    int numerator;
    int denominator;
} Rational;

// Function to compute the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to create a rational number
Rational rat_create(int numerator, int denominator) {
    Rational r;
    r.numerator = numerator;
    r.denominator = denominator;
    return r;
}

// Function to normalize a rational number (reduce to lowest terms)
void rat_normalize(Rational *r) {
    int common_divisor = gcd(abs(r->numerator), abs(r->denominator));
    r->numerator /= common_divisor;
    r->denominator /= common_divisor;
    
    // Ensure the denominator is positive
    if (r->denominator < 0) {
        r->numerator = -r->numerator;
        r->denominator = -r->denominator;
    }
}

// Function to print the normalized form of a rational number
void rat_print_normalized(Rational *r) {
    Rational temp = *r; // Create a copy to preserve original
    rat_normalize(&temp); // Normalize the copy
    printf("Normalized form: %d/%d\n", temp.numerator, temp.denominator);
}

// Function to print the original form of a rational number
void rat_print_original(Rational *r) {
    printf("Original form: %d/%d\n", r->numerator, r->denominator);
}

int main() {
    // Example usage:
    Rational r = rat_create(2, 4); // Rational number 2/4
    
    // Print normalized form
    rat_print_normalized(&r);
    
    // Print original form
    rat_print_original(&r);
    
    return 0;
}

