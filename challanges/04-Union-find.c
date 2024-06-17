/* Union-Find 
   ==========
   The Union-Find problem deals with the representation of partitions over a base set. 
   We will identify the elements of the base set using the numbers 0, 1, ... and will 
   represent partitions with a forest data structure where each element knows
has a “parent” that is another element inside the same partition. Each set in such a 
partition is identified by a designated element called the root of the set.
We want to perform two principal operations:
• A Find operation receives one element of the ground set and returns the root of
the corresponding set.
• A Unionaoperation receives two elements and merges the two sets to which these
elements belong into one.
~
~
~
Output : -
===========================================
Enter the number of elements : 10
Enter the indices for find operations : 4 8
Find root of 4 is 4
Find root of 8 is 8
Enter the indices for Union operations :8 4
Find the root of 8 after union is 8
Find the root of 4 after union is 8
===========================================
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

size_t parent[SIZE];

void initial(size_t n)
{
    for (size_t i = 0; i < n; i++) {
	parent[i] = i;
    }
}

size_t find(size_t i)
{
    while (parent[i] != i) {
	i = parent[i];
    }
    return i;
}

void Union(size_t i1, size_t i2)
{
    size_t root1 = find(i1);
    size_t root2 = find(i2);

    if (root1 != root2) {
	parent[root2] = root1;
    }
}

int main()
{
    size_t n;
    printf("Enter the number of elements : ");
    scanf("%zu", &n);
    initial(n);

    size_t i1, i2;
    printf("Enter the indices for find operations : ");
    scanf("%zu %zu", &i1, &i2);
    printf("Find root of %zu is %zu\n", i1, find(i1));
    printf("Find root of %zu is %zu\n", i2, find(i2));

    printf("Enter the indices for Union operations :");
    scanf("%zu %zu", &i1, &i2);
    Union(i1, i2);
    printf("Find the root of %zu after union is %zu\n", i1, find(i1));
    printf("Find the root of %zu after union is %zu\n", i2, find(i2));
    return 0;
}
