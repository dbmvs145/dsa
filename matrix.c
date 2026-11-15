#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Allocate 2D matrix dynamically
int **allocate(int rows, int cols)
{
    int **mat = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        mat[i] = (int *)malloc(cols * sizeof(int));
    return mat;
}

void freeMat(int **mat, int rows)
{
    for (int i = 0; i < rows; i++)
        free(mat[i]);
    free(mat);
}

// 1. Generate random matrix and save to file
void generateMatrix(char *filename, int rows, int cols, int low, int high)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Cannot open %s\n", filename);
        exit(1);
    }
    fprintf(fp, "%d %d\n", rows, cols); // first line = dimensions

    srand(time(0) + rand()); // different seed each call
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int val = low + rand() % (high - low + 1);
            fprintf(fp, "%d ", val);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Matrix %dx%d saved to %s\n", rows, cols, filename);
}

// 2. Read matrix from file
int **readMatrix(char *filename, int *rows, int *cols)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Cannot open %s\n", filename);
        exit(1);
    }
    fscanf(fp, "%d %d", rows, cols);
    int **mat = allocate(*rows, *cols);
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *cols; j++)
            fscanf(fp, "%d", &mat[i][j]);
    fclose(fp);
    return mat;
}

// 3. Multiply - Check possibility
int **multiply(int **A, int **B, int r1, int c1, int r2, int c2, int *r3, int *c3)
{
    if (c1 != r2)
    {
        printf("\nMultiplication NOT possible! cols of A (%d) != rows of B (%d)\n", c1, r2);
        return NULL;
    }
    *r3 = r1;
    *c3 = c2;
    int **C = allocate(*r3, *c3);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            long sum = 0;
            for (int k = 0; k < c1; k++)
                sum += (long)A[i][k] * B[k][j];
            C[i][j] = (int)sum;
        }
    }
    return C;
}

// 4. Write result to file
void writeMatrix(char *filename, int **mat, int rows, int cols)
{
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            fprintf(fp, "%d ", mat[i][j]);
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Result %dx%d saved to %s\n", rows, cols, filename);
}

int main(int argc, char *argv[])
{
    // All file names from command line
    if (argc != 4)
    {
        printf("Usage: %s <file1> <file2> <result_file>\n", argv[0]);
        printf("Example: %s matA.txt matB.txt result.txt\n", argv[0]);
        return 1;
    }

    char *file1 = argv[1];
    char *file2 = argv[2];
    char *file3 = argv[3];

    int r1, c1, r2, c2, low, high;
    printf("Enter rows cols for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows cols for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter range low high: ");
    scanf("%d %d", &low, &high);

    // Step 1: Generate and save
    generateMatrix(file1, r1, c1, low, high);
    generateMatrix(file2, r2, c2, low, high);

    // Step 2: Read back from files (as per question)
    int ar, ac, br, bc;
    int **A = readMatrix(file1, &ar, &ac);
    int **B = readMatrix(file2, &br, &bc);

    // Step 3: Multiply with check
    int r3, c3;
    int **C = multiply(A, B, ar, ac, br, bc, &r3, &c3);
    if (C == NULL)
    {
        freeMat(A, ar);
        freeMat(B, br);
        return 1;
    }

    // Step 4: Save result
    writeMatrix(file3, C, r3, c3);

    freeMat(A, ar);
    freeMat(B, br);
    freeMat(C, r3);
    return 0;
}
