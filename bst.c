#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        printf("Duplicate %d not allowed\n", val);
    }
    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

struct Node* findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        printf("Key %d not found\n", key);
        return root;
    }
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node found
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            printf("%d deleted\n", key);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            printf("%d deleted\n", key);
            return temp;
        }
        else
        {
            // 2 children - inorder successor
            struct Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void createBST()
{
    int n, i, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("BST Created\n");
}

int main()
{
    int choice, val;
    struct Node *result;

    while (1)
    {
        printf("\n--- BST MENU ---\n");
        printf("1.Create BST\n");
        printf("2.Insertion\n");
        printf("3.Inorder Traversal\n");
        printf("4.Preorder Traversal\n");
        printf("5.Postorder Traversal\n");
        printf("6.Searching\n");
        printf("7.Deletion\n");
        printf("8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                root = NULL;
                createBST();
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("%d inserted\n", val);
                break;
            case 3:
                printf("Inorder (Sorted): ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Enter key to search: ");
                scanf("%d", &val);
                result = search(root, val);
                if (result != NULL)
                {
                    printf("%d FOUND in BST\n", val);
                }
                else
                {
                    printf("%d NOT FOUND\n", val);
                }
                break;
            case 7:
                printf("Enter key to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}
