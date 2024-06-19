/* 
===============================================================================
Design a union type to investigate the bytes of a pointer type, such as double* 
===============================================================================
Output :
======================================
Size of double*: 8 bytes
Bytes of the pointer (in hexadecimal):
0000000000000000
======================================
*/
#include <stdio.h>
#include <stdint.h> // For uintptr_t
#include <inttypes.h> // For PRIxPTR

// Union to investigate the bytes of a pointer type
union PointerBytes {
    double *ptr;
    uintptr_t bytes[sizeof(double*) / sizeof(uintptr_t)]; // Use uintptr_t for portable pointer size
};

int main() {
    union PointerBytes pb;
    pb.ptr = NULL; // Replace NULL with the pointer you want to investigate

    printf("Size of double*: %zu bytes\n", sizeof(double*));

    // Print the bytes of the pointer
    printf("Bytes of the pointer (in hexadecimal):\n");
    for (size_t i = 0; i < sizeof(double*) / sizeof(uintptr_t); ++i) {
        printf("%016" PRIxPTR "\n", (uintptr_t)pb.bytes[i]); // Cast to uintptr_t
    }

    return 0;
}
