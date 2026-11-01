#include <stdio.h>
#include <stdlib.h>
#define MAX 101

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
    arr[0] = 0; // reserve for sentinel
}

// 1. MODIFIED BUBBLE SORT
void modifiedBubbleSort()
{
    int i, j, temp;
    int swapped;
    for (i = 1; i <= n-1; i++)
    {
        swapped = 0;
        for (j = 1; j <= n-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            printf("Early exit at pass %d - already sorted\n", i);
            break;
        }
    }
    printf("Sorted using Modified Bubble Sort\n");
}

// 2. INSERTION SORT USING SENTINEL
void insertionSortSentinel()
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        arr[0] = arr[i]; // sentinel stores current
        j = i - 1;
        while (arr[j] > arr[0])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = arr[0];
    }
    printf("Sorted using Insertion Sort with Sentinel\n");
}

// 3. SHELL SORT
void shellSort()
{
    int gap, i, j, temp;
    for (gap = n/2; gap >= 1; gap = gap/2)
    {
        for (i = gap+1; i <= n; i++)
        {
            temp = arr[i];
            j = i - gap;
            while (j >= 1 && arr[j] > temp)
            {
                arr[j+gap] = arr[j];
                j = j - gap;
            }
            arr[j+gap] = temp;
        }
        printf("After gap %d: ", gap);
        display();
    }
    printf("Sorted using Shell Sort\n");
}

int main()
{
    int choice;

    inputArray();

    while (1)
    {
        printf("\n--- SORTING MENU ---\n");
        printf("1.Display Array\n");
        printf("2.Input New Array\n");
        printf("3.Modified Bubble Sort\n");
        printf("4.Insertion Sort using Sentinel\n");
        printf("5.Shell Sort\n");
        printf("6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display();
                break;
            case 2:
                inputArray();
                break;
            case 3:
                modifiedBubbleSort();
                display();
                break;
            case 4:
                insertionSortSentinel();
                display();
                break;
            case 5:
                shellSort();
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
