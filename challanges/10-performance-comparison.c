/* 
############################################
Performance comparison of sorting algorithms
############################################
Compare the time efficiency of the sorting programs 
(such as quick sort and merge sort) with data sizes 
of several orders of magnitude
---------------------------------------------------
Output : -
###########################################################
Size (N)        Quicksort Time (ms)     Mergesort Time (ms)
1000            0.419000                        0.560000
5000            2.124000                        0.612000
10000           0.937000                        1.277000
50000           5.865000                        7.072000
100000          11.863000                       15.596000
##########################################################
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random array of size n
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

// Function to perform the quicksort algorithm
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to merge two subarrays of arr[]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
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

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform the mergesort algorithm
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    //srand(time(NULL)); // Seed for random number generation

    int sizes[] = {1000, 5000, 10000, 50000, 100000}; // Different sizes of arrays to test
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("###########################################################\n");
    printf("Size (N)\tQuicksort Time (ms)\tMergesort Time (ms)\n");

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int arr[size];

        // Generate random array
        generateRandomArray(arr, size);

        // Measure time taken by quicksort
        clock_t start = clock();
        quicksort(arr, 0, size - 1);
        clock_t end = clock();
        double quicksort_time = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;

        // Generate random array again for mergesort
        generateRandomArray(arr, size);

        // Measure time taken by mergesort
        start = clock();
        mergesort(arr, 0, size - 1);
        end = clock();
        double mergesort_time = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;

        printf("%d\t\t%.6f\t\t\t%.6f\n", size, quicksort_time, mergesort_time);
        
    }
    printf("##########################################################\n");
    return 0;
}
