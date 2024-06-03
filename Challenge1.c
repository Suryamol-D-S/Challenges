// Quick sort with recursion

#include <stdio.h>

int partition(int ar[], int low, int high)
{
    int max = ar[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (ar[j] <= max)
        {
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
    if (low < high)
    {
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
    for (int i = 0; i < n; i++)
    {
        printf("Element - %d: ", i);
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    puts("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);

    }
}