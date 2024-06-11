/*
The second return of hexatridecimal makes an assumption about the the relation betweeen a and 'A'.  What is it?

- The ASCII value of an uppercase letter is always greater than or equal to the ASCII value of its corresponding lowercase letter by a fixed offset.
- Therefore, if we subtract the ASCII value of 'A' from the ASCII value of an uppercase letter, we get an integer value that represents its position 
in the alphabet, starting from 0 for 'A', 1 for 'B', and so on.
-
-
-
Output :-
hexatridecimal('0') = 0
hexatridecimal('9') = 9
hexatridecimal('A') = 10
hexatridecimal('Z') = 35
hexatridecimal('a') = 10
hexatridecimal('z') = 35
hexatridecimal('$') = -1

*/

#include <stdio.h>
#include <ctype.h>

unsigned hexatridecimal(int a) {
    if (isdigit(a)) {
        return a - '0';
    } else {
        a = toupper(a);
        return (isupper(a)) ? 10 + (a - 'A') : -1;
    }
}

int main() {
    printf("hexatridecimal('0') = %u\n", hexatridecimal('0'));
    printf("hexatridecimal('9') = %u\n", hexatridecimal('9'));
    printf("hexatridecimal('A') = %u\n", hexatridecimal('A'));
    printf("hexatridecimal('Z') = %u\n", hexatridecimal('Z'));
    printf("hexatridecimal('a') = %u\n", hexatridecimal('a'));
    printf("hexatridecimal('z') = %u\n", hexatridecimal('z'));
    printf("hexatridecimal('$') = %d\n", hexatridecimal('$'));
    return 0;
}
