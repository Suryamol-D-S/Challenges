/*The function rat_get_prod can produce intermediate values that may cause it to produce wrong results, even if the mathematical result of the multiplication is representable in rat. How is that?

Output :-
Enter the numerator and denominator of the first rational number (separated by a space): 20 3
Enter the numerator and denominator of the second rational number (separated by a space): 7 6
Product: 140/18
*/
#include <stdio.h>

// Structure to represent a rational number
typedef struct {
    int numerator;
    int denominator;
} Rational;

// Function to multiply two rational numbers
Rational rat_get_prod(Rational a, Rational b)
{
    Rational result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return (result);
}

int main()
{
    Rational a, b;

    // Input for the first rational number
    printf
	("Enter the numerator and denominator of the first rational number (separated by a space): ");
    scanf("%d %d", &a.numerator, &a.denominator);

    // Input for the second rational number
    printf
	("Enter the numerator and denominator of the second rational number (separated by a space): ");
    scanf("%d %d", &b.numerator, &b.denominator);

    // Multiply the rational numbers
    Rational product = rat_get_prod(a, b);

    // Print the result
    printf("Product: %d/%d\n", product.numerator, product.denominator);

    return (0);
}
