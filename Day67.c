/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adj[100];
int visited[100];
int stack[100];
int top = -1;

// Create node
struct Node *createNode(int v)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

// Add edge (directed)
void addEdge(int u, int v)
{
    struct Node *node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
}

// DFS for topo sort
void dfs(int v)
{
    visited[v] = 1;

    struct Node *temp = adj[v];
    while (temp)
    {
        if (!visited[temp->vertex])
        {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }

    stack[++top] = v; // push after recursion
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

    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // call DFS for all components
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    // print topo order (reverse of stack)
    while (top != -1)
    {
        printf("%d ", stack[top--]);
    }

    return 0;
}