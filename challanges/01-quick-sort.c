/* Quick sort with recursion 
   =========================
   Quicksort is a divide-and-conquer algorithm. It works by selecting a 'max' 
   element from the array and partitioning the other elements into two sub-arrays, 
   according to whether they are less than or greater than the max.
   -
   -
   -
   Output :-
   $ c99 -Wall -o 01-quick-sort 01-quick-sort.c -lm
   $ ./01-quick-sort 
   Enter the number of elements in the array: 
   5
   Enter the elements of the array: 
   Element - 0: 3
   Element - 1: 2
   Element - 2: 4
   Element - 3: 5
   Element - 4: 1
   The sorted array is: 
   1
   2
   3
   4
   5*/

#include <stdio.h>

int partition(int ar[], int low, int high)
{
    int max = ar[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
	if (ar[j] <= max) {
	    i++;
	    int temp = ar[i];
	    ar[i] = ar[j];
	    ar[j] = temp;
	}
    }
    int temp = ar[i + 1];
    ar[i + 1] = ar[high];
    ar[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
	int mx = partition(arr, low, high);
	quickSort(arr, low, mx - 1);
	quickSort(arr, mx + 1, high);
    }
}

int main(void)
{
    puts("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    puts("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
	printf("Element - %d: ", i);
	scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    puts("The sorted array is: ");
    for (int i = 0; i < n; i++) {
	printf("%d\n", arr[i]);

    }
}
