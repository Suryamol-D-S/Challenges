#ifndef RATIONAL_H
#define RATIONAL_H

#include <stdbool.h>
#include <stddef.h>

typedef struct{
    bool sign;
    size_t num;
    size_t denom;
} rat;

/* Function declarations */
char const * rat_print(size_t len, char tmp[len], rat const * x);

// Other function prototypes...

#endif /* RATIONAL_H */
