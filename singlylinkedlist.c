#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void createList()
{
    int n, val, i;
    struct Node* newNode;
    struct Node* temp;

    if (head != NULL)
    {
        head = NULL;
    }
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter data %d: ", i+1);
        scanf("%d", &val);
        newNode = createNode(val);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("List created\n");
}

void printList()
{
    struct Node* temp;
    if (head == NULL)
    {
        printf("List is EMPTY\n");
        return;
    }
    printf("List: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertFirst(int val)
{
    struct Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    printf("%d inserted at first\n", val);
}

void insertLast(int val)
{
    struct Node* newNode = createNode(val);
    struct Node* temp;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at last\n", val);
}

void insertAtPosition(int pos, int val)
{
    int i;
    struct Node* newNode;
    struct Node* temp;
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        insertFirst(val);
        return;
    }
    newNode = createNode(val);
    temp = head;
    for (i = 1; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at pos %d\n", val, pos);
}

void insertAfterData(int key, int val)
{
    struct Node* temp = head;
    struct Node* newNode;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Data %d not found\n", key);
        return;
    }
    newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted after %d\n", val, key);
}

void deleteFirst()
{
    struct Node* temp;
    if (head == NULL)
    {
        printf("List EMPTY\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("%d deleted from first\n", temp->data);
    free(temp);
}

void deleteLast()
{
    struct Node* temp;
    struct Node* prev;
    if (head == NULL)
    {
        printf("List EMPTY\n");
        return;
    }
    if (head->next == NULL)
    {
        printf("%d deleted from last\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("%d deleted from last\n", temp->data);
    free(temp);
}

void deleteAtPosition(int pos)
{
    int i;
    struct Node* temp;
    struct Node* delNode;
    if (head == NULL)
    {
        printf("List EMPTY\n");
        return;
    }
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        deleteFirst();
        return;
    }
    temp = head;
    for (i = 1; i < pos-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    delNode = temp->next;
    temp->next = delNode->next;
    printf("%d deleted from pos %d\n", delNode->data, pos);
    free(delNode);
}

void deleteData(int key)
{
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (head == NULL)
    {
        printf("List EMPTY\n");
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Data %d not found\n", key);
        return;
    }
    if (prev == NULL)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }
    printf("%d deleted\n", temp->data);
    free(temp);
}

void countNodes()
{
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Total elements: %d\n", count);
}

void searchPresent(int key)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("%d is PRESENT\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("%d NOT PRESENT\n", key);
}

void searchPosition(int key)
{
    int pos = 1;
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("%d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d NOT FOUND\n", key);
}

void searchCount(int key)
{
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            count++;
        }
        temp = temp->next;
    }
    printf("Occurrence of %d: %d times\n", key, count);
}

void sortList()
{
    int tempData;
    struct Node* i;
    struct Node* j;
    if (head == NULL)
    {
        printf("List EMPTY\n");
        return;
    }
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
    printf("List sorted\n");
}

void reverseList()
{
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    if (head == NULL)
    {
        printf("List EMPTY\n");
        return;
    }
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed\n");
}

int main()
{
    int choice, val, pos, key;

    while (1)
    {
        printf("\n--- SINGLE MENU ---\n");
        printf("1.Create List\n");
        printf("2.Print List\n");
        printf("3.Insert at First\n");
        printf("4.Insert at Last\n");
        printf("5.Insert at Position\n");
        printf("6.Insert after Data\n");
        printf("7.Delete First\n");
        printf("8.Delete Last\n");
        printf("9.Delete from Position\n");
        printf("10.Delete Given Data\n");
        printf("11.Count Elements\n");
        printf("12.Search Presence\n");
        printf("13.Search Position\n");
        printf("14.Search Count\n");
        printf("15.Sort List\n");
        printf("16.Reverse List\n");
        printf("17.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createList();
                break;
            case 2:
                printList();
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFirst(val);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                insertLast(val);
                break;
            case 5:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                insertAtPosition(pos, val);
                break;
            case 6:
                printf("Enter existing data and new value: ");
                scanf("%d %d", &key, &val);
                insertAfterData(key, val);
                break;
            case 7:
                deleteFirst();
                break;
            case 8:
                deleteLast();
                break;
            case 9:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 10:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                deleteData(key);
                break;
            case 11:
                countNodes();
                break;
            case 12:
                printf("Enter data to search: ");
                scanf("%d", &key);
                searchPresent(key);
                break;
            case 13:
                printf("Enter data to search: ");
                scanf("%d", &key);
                searchPosition(key);
                break;
            case 14:
                printf("Enter data to search: ");
                scanf("%d", &key);
                searchCount(key);
                break;
            case 15:
                sortList();
                break;
            case 16:
                reverseList();
                break;
            case 17:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
