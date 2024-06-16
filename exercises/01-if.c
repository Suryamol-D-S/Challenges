/* Add the if(i) condition to the program, and compare the output of first example
 * Output of First code :
 * element 0 is 9,         its square is 81
 * element 1 is 2.9,       its square is 8.41
 * element 2 is 0,         its square is 0
 * element 3 is 7e-05,     its square is 4.9e-09
 * element 4 is 3e+25,     its square is 9e+50
 *
 * Output of this code :
 * element 1 is 2.9,       its square is 8.41
 * element 2 is 0,         its square is 0
 * element 3 is 7e-05,     its square is 4.9e-09
 * element 4 is 3e+25,     its square is 9e+50
 * -
 * -
 * -
 * Here the difference is that first code is started with the index 0 and second is started with index 1.
 */

#include <stdio.h>
int main()
{
    double A[5] = {
	[0] = 9.0,
	[1] = 2.9,
	[4] = 3.E+25,
	[3] = .00007,
    };
    for (size_t i = 0; i < 5; ++i) {
	if (i) {
	    printf("element %zu is %g, \tits square is %g\n",
		   i, A[i], A[i] * A[i]);
	}
    }
}
