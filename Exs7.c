// test example switch statement in a program.  See what happen if you leave out some of the break

#include <stdio.h>
int main() {
    int count;
    printf("Enter the count : ");
    scanf("%d", &count);
    switch ( count ) {
    default : puts ("++++.....+++ ");
    case 4: puts ("++++ ");
    case 3: puts ("+++ ");
    case 2: puts ("++ ");
    case 1: puts ("+");
    case 0:;
    }
}