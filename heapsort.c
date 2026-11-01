#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX];
int n;

void display()
{
    int i;
    if (n == 0)
    {
        printf("Array EMPTY\n");
        return;
    }
    printf("Array: ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void inputArray()
{
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void heapifyMax(int size, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    int temp;

    if (left <= size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapifyMax(size, largest);
    }
}

void heapifyMin(int size, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    int temp;

    if (left <= size && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right <= size && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapifyMin(size, smallest);
    }
}

void heapSortAscending()
{
    int i, temp;
    for (i = n/2; i >= 1; i--)
    {
        heapifyMax(n, i);
    }
    printf("Max Heap: ");
    display();

    for (i = n; i >= 2; i--)
    {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapifyMax(i-1, 1);
    }
    printf("Sorted Ascending using Heap Sort\n");
}

void heapSortDescending()
{
    int i, temp;
    for (i = n/2; i >= 1; i--)
    {
        heapifyMin(n, i);
    }
    printf("Min Heap: ");
    display();

    for (i = n; i >= 2; i--)
    {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapifyMin(i-1, 1);
    }
    printf("Sorted Descending using Heap Sort\n");
}

int main()
{
    int choice;

    inputArray();

    while (1)
    {
        printf("\n--- HEAP SORT MENU ---\n");
        printf("1.Input Array\n");
        printf("2.Display Array\n");
        printf("3.Heap Sort Ascending\n");
        printf("4.Heap Sort Descending\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                inputArray();
                break;
            case 2:
                display();
                break;
            case 3:
                heapSortAscending();
                display();
                break;
            case 4:
                heapSortDescending();
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
