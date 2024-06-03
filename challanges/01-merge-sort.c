/* Merge Sort using recursion
-------------------------------
Merge sort is a sorting algorithm that follows the divide-and-conquer approach. 
It works by recursively dividing the input array into smaller subarrays and sorting 
those subarrays then merging them back together to obtain the sorted array
-
-
-
Output :-
suryanol@Elanor:~/Desktop/Challenges/challanges$ gcc -o 01-merge-sort 01-merge-sort.c 
suryanol@Elanor:~/Desktop/Challenges/challanges$ ./01-merge-sort 
Enter the number of elements: 10
Enter the elements:
3 5 1 8 9 10 0 3 6 2

Sorted array is 
0 1 2 3 3 5 6 8 9 10 */

#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Main Code
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    mergeSort(arr, 0, n - 1);

    printf("\nSorted array is \n");
    for(int i=0 ; i<n ; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
