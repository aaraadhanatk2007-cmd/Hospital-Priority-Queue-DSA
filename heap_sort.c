#include <stdio.h>

int comparisons = 0;
int swaps = 0;

void display(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = *a;

    swaps++;
}

void heapify(int a[], int n, int i)
{
    int largest;
    int left, right;

    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if(left < n)
    {
        comparisons++;

        if(a[left] > a[largest])
            largest = left;
    }

    if(right < n)
    {
        comparisons++;

        if(a[right] > a[largest])
            largest = right;
    }

    if(largest != i)
    {
        int temp;

        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        swaps++;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i;
    int temp;

    printf("\nBuilding Max Heap...\n");

    for(i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    printf("Max Heap: ");
    display(a, n);

    printf("\nHeap Sort Steps:\n");

    for(i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        swaps++;

        heapify(a, i, 0);

        printf("After moving maximum to position %d: ", i);
        display(a, n);
    }
}

int main()
{
    int a[] = {45, 72, 30, 90, 65, 50, 85};
    int n = 7;

    printf("HEAP SORT\n");
    printf("---------\n");

    printf("Original array: ");
    display(a, n);

    heapSort(a, n);

    printf("\nFinal sorted array: ");
    display(a, n);

    printf("\nTotal comparisons: %d\n", comparisons);
    printf("Total swaps: %d\n", swaps);

    return 0;
}
