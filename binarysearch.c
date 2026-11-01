#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX];
int n;

void sortAscending()
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarySearch(int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void display()
{
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice, key, result, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (sorted order better): ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\n--- BINARY SEARCH MENU ---\n");
        printf("1.Display Array\n");
        printf("2.Sort Array\n");
        printf("3.Search Element\n");
        printf("4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display();
                break;
            case 2:
                sortAscending();
                printf("Array sorted\n");
                display();
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                sortAscending();
                result = binarySearch(key);
                if (result != -1)
                {
                    printf("%d found at index %d\n", key, result);
                }
                else
                {
                    printf("%d NOT FOUND\n", key);
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
