#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define a structure representing a person
typedef struct {
    char name[50];
    int age;
    double salary;
} Person;

// Comparison function pointer type for qsort-like interface
typedef int (*cmp_func_t)(const void *, const void *);

// Partition function for quicksort
int partition(void *arr, int low, int high, size_t size, cmp_func_t cmp) {
    char *ar = arr;
    char *max = ar + high * size;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (cmp(ar + j * size, max) <= 0) {
            i++;
            for (size_t k = 0; k < size; k++) {
                char temp = ar[i * size + k];
                ar[i * size + k] = ar[j * size + k];
                ar[j * size + k] = temp;
            }
        }
    }
    for (size_t k = 0; k < size; k++) {
        char temp = ar[(i + 1) * size + k];
        ar[(i + 1) * size + k] = ar[high * size + k];
        ar[high * size + k] = temp;
    }
    return i + 1;
}

// Quicksort function with generic interface
void quickSort(void *arr, int low, int high, size_t size, cmp_func_t cmp) {
    if (low < high) {
        int mx = partition(arr, low, high, size, cmp);
        quickSort(arr, low, mx - 1, size, cmp);
        quickSort(arr, mx + 1, high, size, cmp);
    }
}

// Comparison functions for different sort keys
int compareByName(const void *a, const void *b) {
    return strcmp(((Person *)a)->name, ((Person *)b)->name);
}

int compareByAge(const void *a, const void *b) {
    return ((Person *)a)->age - ((Person *)b)->age;
}

int compareBySalary(const void *a, const void *b) {
    if (((Person *)a)->salary < ((Person *)b)->salary) return -1;
    if (((Person *)a)->salary > ((Person *)b)->salary) return 1;
    return 0;
}

int main(void) {
    puts("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    Person arr[n];

    // Input elements of the array
    puts("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        printf("Element - %d (name, age, salary): ", i + 1);
        scanf("%s %d %lf", arr[i].name, &arr[i].age, &arr[i].salary);
    }

    // Sort by name using quickSort
    quickSort(arr, 0, n - 1, sizeof(Person), compareByName);

    // Output sorted array by name
    puts("\nThe sorted array by name is: ");
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %.2f\n", arr[i].name, arr[i].age, arr[i].salary);
    }

    // Sort by age using quickSort
    quickSort(arr, 0, n - 1, sizeof(Person), compareByAge);

    // Output sorted array by age
    puts("\nThe sorted array by age is: ");
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %.2f\n", arr[i].name, arr[i].age, arr[i].salary);
    }

    // Sort by salary using quickSort
    quickSort(arr, 0, n - 1, sizeof(Person), compareBySalary);

    // Output sorted array by salary
    puts("\nThe sorted array by salary is: ");
    for (int i = 0; i < n; i++) {
        printf("%s, %d, %.2f\n", arr[i].name, arr[i].age, arr[i].salary);
    }

    // Performance comparison with qsort
    // Prepare a copy of arr for qsort comparison
    Person arr_copy[n];
    memcpy(arr_copy, arr, n * sizeof(Person));

    clock_t start, end;
    double cpu_time_used;

    // Measure time taken by quickSort for sorting by age
    start = clock();
    quickSort(arr, 0, n - 1, sizeof(Person), compareByAge);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken by quickSort (sorting by age): %.6f seconds\n", cpu_time_used);

    // Measure time taken by qsort for sorting by age
    start = clock();
    qsort(arr_copy, n, sizeof(Person), compareByAge);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by qsort (sorting by age): %.6f seconds\n", cpu_time_used);

    return 0;
}
