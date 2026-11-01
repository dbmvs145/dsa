#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int hashTable[SIZE];
int flag[SIZE]; // 0=empty, 1=occupied, 2=deleted

void initTable()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        flag[i] = 0;
        hashTable[i] = 0;
    }
    printf("Hash Table initialized (Size %d)\n", SIZE);
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int i, index, h;
    h = hashFunction(key);

    for (i = 0; i < SIZE; i++)
    {
        index = (h + i) % SIZE;
        if (flag[index] == 0 || flag[index] == 2)
        {
            hashTable[index] = key;
            flag[index] = 1;
            printf("%d inserted at index %d\n", key, index);
            return;
        }
    }
    printf("Hash Table FULL, cannot insert %d\n", key);
}

void search(int key)
{
    int i, index, h;
    h = hashFunction(key);

    for (i = 0; i < SIZE; i++)
    {
        index = (h + i) % SIZE;
        if (flag[index] == 0)
        {
            printf("%d NOT FOUND\n", key);
            return;
        }
        if (flag[index] == 1 && hashTable[index] == key)
        {
            printf("%d FOUND at index %d\n", key, index);
            return;
        }
    }
    printf("%d NOT FOUND\n", key);
}

void deleteKey(int key)
{
    int i, index, h;
    h = hashFunction(key);

    for (i = 0; i < SIZE; i++)
    {
        index = (h + i) % SIZE;
        if (flag[index] == 0)
        {
            printf("%d NOT FOUND\n", key);
            return;
        }
        if (flag[index] == 1 && hashTable[index] == key)
        {
            flag[index] = 2;
            printf("%d deleted from index %d\n", key, index);
            return;
        }
    }
    printf("%d NOT FOUND\n", key);
}

void display()
{
    int i;
    printf("\n--- Hash Table ---\n");
    printf("Index  Key  Status\n");
    for (i = 0; i < SIZE; i++)
    {
        if (flag[i] == 1)
        {
            printf("%5d %5d  Occupied\n", i, hashTable[i]);
        }
        else if (flag[i] == 2)
        {
            printf("%5d  ----  Deleted\n", i);
        }
        else
        {
            printf("%5d  ----  Empty\n", i);
        }
    }
}

int main()
{
    int choice, key;

    initTable();

    while (1)
    {
        printf("\n--- HASHING MENU (Linear Probing) ---\n");
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 4:
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
