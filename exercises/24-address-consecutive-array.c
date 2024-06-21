/*With such a union, investigate the address of two consecutive elements of an array.

Output :-
Address of arr[0]: 0x7ffeadad1640
Address of arr[1]: 0x7ffeadad1648
Address of arr[0] (uintptr_t): 0x7ffeadad1640
Address of arr[1] (uintptr_t): 0x40091eb851eb851f
*/

#include <stdio.h>
#include <stdint.h> // Include for uintptr_t type

// Union to investigate pointer bytes
union PointerBytes {
    double *ptr;
    uintptr_t bytes[sizeof(double*) / sizeof(uintptr_t)]; // Use uintptr_t for portable pointer size
};

int main() {
    double arr[] = { 3.14, 2.71, 1.618 }; // Example array of doubles

    // Print the addresses of two consecutive elements
    printf("Address of arr[0]: %p\n", (void *)&arr[0]);
    printf("Address of arr[1]: %p\n", (void *)&arr[1]);

    // Union to interpret the addresses
    union PointerBytes pb;

    // Assign the address of arr[0] to the union
    pb.ptr = &arr[0];

    // Print the addresses as uintptr_t (for illustration)
    printf("Address of arr[0] (uintptr_t): 0x%lx\n", pb.bytes[0]);
    printf("Address of arr[1] (uintptr_t): 0x%lx\n", pb.bytes[1]);

    return 0;
}

