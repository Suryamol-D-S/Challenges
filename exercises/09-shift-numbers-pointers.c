/*
================================================================
 Write a function that receives pointers to three objects and
shifts the values of these objects cyclically
================================================================
Output : -
***************************
num1     num2    num3
12      34      45
Before shifting: 12, 34, 45
After shifting: 34, 45, 12
****************************
*/
#include <stdio.h>

void cyclically(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

int main() {
    int num1, num2, num3;
    printf("num1\t num2\t num3\n");
    scanf("%d\t %d\t %d", &num1, &num2, &num3);

    int *ptr1 = &num1, *ptr2 = &num2, *ptr3 = &num3;
    
    printf("Before shifting: %d, %d, %d\n", *ptr1, *ptr2, *ptr3);
    
    cyclically(ptr1, ptr2, ptr3);
    
    printf("After shifting: %d, %d, %d\n", *ptr1, *ptr2, *ptr3);

    return 0;
}
