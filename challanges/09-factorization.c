// Factorization

#include <stdio.h>

// Function to print all prime factors of a number
void print_prime_factors(size_t n, size_t divisor) {
    // Base case: if the number becomes 1, stop recursion
    if (n == 1) {
        printf("\n");
        return;
    }
    
    // If the current divisor can divide the number
    // then it's a prime factor
    if (n % divisor == 0) {
        printf("%zu ", divisor);
        // Recursively find factors of n divided by divisor
        print_prime_factors(n / divisor, divisor);
    }
    // If the current divisor cannot divide the number,
    // try the next divisor
    else {
        print_prime_factors(n, divisor + 1);
    }
}

int main() {
    size_t n;

    printf("Enter a number: ");
    scanf("%zu", &n);

    printf("%zu: ", n);
    print_prime_factors(n, 2);

    return 0;
}
