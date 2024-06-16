/* Show that if the minimal and maximal values for signed long long have similar properties, the smallest
integer value for the platform can’t be written as a combination of one literal with a minus sign. 

Output :
Min: -9223372036854775808
Combination: -9223372036854775808
-
-
-
As seen in the output, the combination is equal to the minimum value itself and cannot be expressed differently. 
Therefore, the smallest integer value for the platform (-9223372036854775808) cannot be written as a combination of one literal with a minus sign.
*/


#include <stdio.h>
#include <limits.h>

int main()
{
    long long int min = LLONG_MIN;

    // Attempt to write the smallest integer value with a minus sign
    long long int combination = -min;

    printf("Min: %lld\n", min);
    printf("Combination: %lld\n", combination);

    return 0;
}
