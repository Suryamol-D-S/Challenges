/* Compute N first decimal places of pi
-
-
-
This code simply done by using for loop.  The program prints the initial part of pi (3.) as a fixed part of the output.
It then enters a loop to print the next n digits of pi.
Inside the loop, it accesses each digit of pi from a predefined string literal 
"14159265358979323846264338327950288419716939937510" using array indexing ([i]) 
and prints it using printf with %c format specifier to print a single character.

Output :-
Enter the number of decimal places of pi to print: 4
Pi: 3.1415
*/

#include <stdio.h>

int main() {
    // Number of decimal places to print
    int n;

    // Prompt user to enter the number of decimal places
    printf("Enter the number of decimal places of pi to print: ");
    scanf("%d", &n);

    // Print pi with the desired number of decimal places
    printf("Pi: 3.");
    for (int i = 0; i < n; ++i) {
        printf("%c","14159265358979323846264338327950288419716939937510"[i]);
    }
    printf("\n");

    return 0;
}
