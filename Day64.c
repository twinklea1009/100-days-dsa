/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order  */
#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adj[100];
int visited[100];

// Create node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v)
{
    struct Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // For undirected graph, uncomment:
    // newNode = createNode(u);
    // newNode->next = adj[v];
    // adj[v] = newNode;
}

// BFS function
void bfs(int start)
{
    int queue[100];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        struct Node *temp = adj[node];
        while (temp)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // input edges
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    scanf("%d", &start);

    bfs(start);

    return 0;
}