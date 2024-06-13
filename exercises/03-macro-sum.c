/* Consider a macro sum(a, b) that is implemented as a+b. What is the result of sum(5, 2)*7 
-------------------------------------------------------------------------------------------
###########
Output : -
Result: 49
###########
*/

#include <stdio.h>

// Define macro for sum of two values
#define sum(a, b) (a + b)

int main() {
    // Evaluate sum(5, 2)*7
    int result = sum(5, 2) * 7;

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}
