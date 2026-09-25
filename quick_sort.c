#include <stdio.h>

int comparisons = 0;
int swaps = 0;

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

    swaps++;
}

int partition(int a[], int low, int high)
{
    int pivot;
    int i, j;

    pivot = a[high];
    i = low - 1;

    for(j = low; j < high; j++)
    {
        comparisons++;

        if(a[j] <= pivot)
        {
            i++;

            if(i != j)
                swap(&a[i], &a[j]);
        }
    }

    if(i + 1 != high)
        swap(&a[i + 1], &a[high]);

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int p;

    if(low < high)
    {
        p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void display(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[] = {45, 72, 30, 90, 65, 50, 85};
    int n = 7;

    printf("Original array: ");
    display(a, n);

    quickSort(a, 0, n - 1);

    printf("Sorted array using Quick Sort: ");
    display(a, n);

    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);

    return 0;
}
