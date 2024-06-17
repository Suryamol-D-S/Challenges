/* Show that A \ B can be computed by A - (A&B) 
================================================
Output : -
A\B is {5, 6, 7}
*/

#include <stdio.h>
int setDifference(int A[], int sizeA, int B[], int sizeB);
int main()
{
    int A[] = { 4, 5, 6, 7 };
    int B[] = { 0, 1, 2, 3, 4, 8 };
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);
    setDifference(A, sizeA, B, sizeB);
}

int setDifference(int A[], int sizeA, int B[], int sizeB)
{
    int temp[sizeA];
    int k = 0;
    for (int i = 0; i < sizeA; i++) {
	int APresentINB = 0;

	for (int j = 0; j < sizeB; j++) {
	    if (A[i] == B[j]) {
		APresentINB = 1;
		break;
	    }

	}

	if (!APresentINB) {
	    temp[k] = A[i];
	    k++;
	}
    }
    printf("A\\B is {");
    for (int i = 0; i < k; i++) {
	printf("%d", temp[i]);
	if (i < k - 1) {
	    printf(", ");
	}

    }
    printf("}\n");
}
