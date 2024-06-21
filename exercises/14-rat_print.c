/*Implement function rat_print as declared in listing 10.1. This function should use -> to access the members of its rat* argument. The printout should have the form ±nom/denum.

Output :-
Rational number: +3/4
Rational number: -3/4
*/
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "rational.h"  // Assuming your header file is named "rational.h"


char const * rat_print(size_t len, char tmp[len], rat const * x) {
    if (x == NULL) {
        snprintf(tmp, len, "NULL");
        return tmp;
    }

    // Determine the sign part
    char sign_char = x->sign ? '+' : '-';

    // Print numerator and denominator
    snprintf(tmp, len, "%c%zu/%zu", sign_char, x->num, x->denom);

    return tmp;
}

int main() {
    // Example usage
    rat my_rat1 = { true, 3, 4 };  // Represents the rational number +3/4
    rat my_rat2 = { false, 3, 4 };  // Represents the rational number -3/4
    char buffer1[50];  // Buffer to hold the printed result
    char buffer2[50];  // Buffer to hold the printed result

    rat_print(sizeof(buffer1), buffer1, &my_rat1);
    rat_print(sizeof(buffer2), buffer2, &my_rat2);

    printf("Rational number: %s\n", buffer1);
    printf("Rational number: %s\n", buffer2);

    return 0;
}
