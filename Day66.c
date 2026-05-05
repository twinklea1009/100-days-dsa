/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists    */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adj[100];
int visited[100];
int recStack[100];

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

// DFS with recursion stack
int dfs(int v)
{
    visited[v] = 1;
    recStack[v] = 1;

    struct Node *temp = adj[v];

    while (temp)
    {
        int nbr = temp->vertex;

        if (!visited[nbr])
        {
            if (dfs(nbr))
                return 1;
        }
        else if (recStack[nbr])
        {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0;
    return 0;
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
        recStack[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}