/* Let max(a, b) be implemented as ((a) < (b) ? (b) : (a)).  What happens for max(i++, 5) ?
-----------------------------------------------------------------------------------------
######################################
Output : -
Result: 5
Value of i after max function call: 2
######################################
*/
#include <stdio.h>
#define max(a, b) ((a) < (b) ? (b) : (a))

int main()
{
    int i = 1;
    int result = max(i++, 5);
    printf("Result: %d\n", result);
    printf("Value of i after max function call: %d\n", i);
    return 0;
}
