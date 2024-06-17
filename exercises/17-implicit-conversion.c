/*Prove that -0x80000000 == 0x80000000
======================================

Under the assumption that the maximum value of unsigned int is 0xFFFFFFFF, prove that -0x80000000 == 0x80000000
-
-
-
Output :
$ c99 -Wall -o 17-implicit-conversion 17-implicit-conversion.c 
$ ./17-implicit-conversion 
0x80000000 is equal to -0x80000000 */

#include <stdio.h>
int main()
{
    unsigned int max_value = 0xFFFFFFFF;
    int neg_value_0x80000000 = -0x80000000;
    if (neg_value_0x80000000 != (int) max_value) {
	printf("0x80000000 is equal to -0x80000000");
    } else {
	printf("0x80000000 is not equal to -0x80000000");
    }
    return 0;
}
