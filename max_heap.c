#include <stdio.h>

#define MAX 20

int heap[MAX];
int size = 0;

int comparisons = 0;
int swaps = 0;

void insert(int value)
{
    int i, parent, temp;

    size++;
    i = size - 1;
    heap[i] = value;

    while(i > 0)
    {
        parent = (i - 1) / 2;

        comparisons++;

        if(heap[parent] >= heap[i])
            break;

        temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        swaps++;

        i = parent;
    }
}

void display()
{
    int i;

    for(i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main()
{
    int a[] = {45, 72, 30, 90, 65, 50, 85};
    int n = 7;
    int i;

    printf("HOSPITAL PRIORITY QUEUE - MAX HEAP\n");
    printf("-----------------------------------\n");

    for(i = 0; i < n; i++)
    {
        insert(a[i]);

        printf("\nAfter inserting %d:\n", a[i]);
        printf("Heap: ");
        display();
    }

    printf("\n-----------------------------------\n");
    printf("Final Max Heap: ");
    display();

    printf("Total comparisons: %d\n", comparisons);
    printf("Total swaps: %d\n", swaps);

    printf("\nHighest priority patient: %d\n", heap[0]);

    return 0;
}
