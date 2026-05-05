/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order    */
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

// DFS function
void dfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    struct Node *temp = adj[v];
    while (temp)
    {
        if (!visited[temp->vertex])
        {
            dfs(temp->vertex);
        }
        temp = temp->next;
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

    dfs(start);

    return 0;
}