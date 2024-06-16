/* Show that if the maximum unsigned is 216 − 1, then -0x8000 has value 32768, too. 

Output :
In signed context: -0x8000 = -32768
In unsigned context: -0x8000 = 32768
*/


#include <stdio.h>

int main()
{
    // Representing -0x8000 in both signed and unsigned contexts
    int signed_value = -0x8000;
    unsigned int unsigned_value = (unsigned int) (signed_value & 0xFFFF);	// Masking to remove sign extension

    printf("In signed context: -0x8000 = %d\n", signed_value);
    printf("In unsigned context: -0x8000 = %u\n", unsigned_value);

    return 0;
}
