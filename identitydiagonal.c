#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int mat[MAX][MAX];
int r, c;

void inputMatrix()
{
    int i, j;
    printf("Enter rows and cols: ");
    scanf("%d %d", &r, &c);
    printf("Enter %d x %d matrix:\n", r, c);
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix()
{
    int i, j;
    if (r == 0)
    {
        printf("Matrix EMPTY\n");
        return;
    }
    printf("Matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int checkDiagonal()
{
    int i, j;
    if (r != c)
    {
        return 0;
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i != j && mat[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int checkIdentity()
{
    int i, j;
    if (r != c)
    {
        return 0;
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i == j && mat[i][j] != 1)
            {
                return 0;
            }
            if (i != j && mat[i][j] != 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int choice;

    inputMatrix();

    while (1)
    {
        printf("\n--- MATRIX CHECK MENU ---\n");
        printf("1.Input Matrix\n");
        printf("2.Display Matrix\n");
        printf("3.Check Diagonal\n");
        printf("4.Check Identity\n");
        printf("5.Check Both\n");
        printf("6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                inputMatrix();
                break;
            case 2:
                displayMatrix();
                break;
            case 3:
                if (checkDiagonal())
                {
                    printf("It is DIAGONAL Matrix\n");
                }
                else
                {
                    printf("It is NOT Diagonal Matrix\n");
                }
                break;
            case 4:
                if (checkIdentity())
                {
                    printf("It is IDENTITY Matrix\n");
                }
                else
                {
                    printf("It is NOT Identity Matrix\n");
                }
                break;
            case 5:
                if (checkIdentity())
                {
                    printf("It is IDENTITY and also DIAGONAL\n");
                }
                else if (checkDiagonal())
                {
                    printf("It is DIAGONAL but NOT Identity\n");
                }
                else
                {
                    printf("It is NEITHER Diagonal nor Identity\n");
                }
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
