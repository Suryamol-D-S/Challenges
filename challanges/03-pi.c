#include <stdio.h>

double calculatePi(int n) {
    double pi = 0.0;
    int sign = 1;
    for (int i = 0; i < n; i++) {
        pi += sign * 4.0 / (2 * i + 1);
        sign *= -1;
    }
    return pi;
}

int main() {
    int decimalPlaces;
    printf("Enter the number of decimal places of pi you want to compute: ");
    scanf("%d", &decimalPlaces);

    double pi = calculatePi(decimalPlaces);
    printf("The value of pi to %d decimal places is: %.*f\n", decimalPlaces, decimalPlaces, pi);

    return 0;
}
