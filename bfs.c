#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if (rear == MAX-1)
    {
        printf("Queue FULL\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = val;
}

int dequeue()
{
    int val;
    if (front == -1 || front > rear)
    {
        return -1;
    }
    val = queue[front];
    front++;
    if (front > rear)
    {
        front = rear = -1;
    }
    return val;
}

int isQueueEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void inputGraph()
{
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
}

void displayGraph()
{
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void bfs(int start)
{
    int i, current;

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    front = rear = -1;

    printf("BFS Traversal starting from %d: ", start);

    enqueue(start);
    visited[start] = 1;

    while (!isQueueEmpty())
    {
        current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void bfsAll()
{
    int i;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    front = rear = -1;

    printf("BFS Traversal (all components): ");
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            enqueue(i);
            visited[i] = 1;
            while (!isQueueEmpty())
            {
                int current = dequeue();
                printf("%d ", current);
                for (int j = 0; j < n; j++)
                {
                    if (adj[current][j] == 1 && visited[j] == 0)
                    {
                        enqueue(j);
                        visited[j] = 1;
                    }
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    int choice, start;

    printf("--- BFS GRAPH INPUT ---\n");
    inputGraph();

    while (1)
    {
        printf("\n--- BFS MENU ---\n");
        printf("1.Input Graph\n");
        printf("2.Display Graph\n");
        printf("3.BFS from a vertex\n");
        printf("4.BFS for all (disconnected graph)\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                inputGraph();
                break;
            case 2:
                displayGraph();
                break;
            case 3:
                printf("Enter starting vertex (0 to %d): ", n-1);
                scanf("%d", &start);
                if (start < 0 || start >= n)
                {
                    printf("Invalid vertex\n");
                }
                else
                {
                    bfs(start);
                }
                break;
            case 4:
                bfsAll();
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
