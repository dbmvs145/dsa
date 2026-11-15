#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node
{
    int data;
    struct Node *next;
} *chain[SIZE];

void init()
{
    for (int i = 0; i < SIZE; i++)
        chain[i] = NULL;
}

int hashFunc(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunc(key);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (chain[index] == NULL)
    {
        chain[index] = newNode;
    }
    else
    {
        struct Node *temp = chain[index];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted at %d\n", key, index);
}

void search(int key)
{
    int index = hashFunc(key);
    struct Node *temp = chain[index];
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("%d found at chain %d\n", key, index);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found\n", key);
}

void deleteKey(int key)
{
    int index = hashFunc(key);
    struct Node *temp = chain[index], *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (prev == NULL)
                chain[index] = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            printf("%d deleted\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not found to delete\n", key);
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("chain[%d] -> ", i);
        struct Node *temp = chain[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int ch, key;
    init();
    while (1)
    {
        printf("\n1.Insert 2.Search 3.Delete 4.Display 5.Exit: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter key: ");
            scanf("%d", &key);
            insert(key);
        }
        else if (ch == 2)
        {
            printf("Enter key: ");
            scanf("%d", &key);
            search(key);
        }
        else if (ch == 3)
        {
            printf("Enter key: ");
            scanf("%d", &key);
            deleteKey(key);
        }
        else if (ch == 4)
        {
            display();
        }
        else break;
    }
    return 0;
}
