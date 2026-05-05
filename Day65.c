/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO    */
#include <stdio.h>
#include <stdlib.h>

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

// Add edge (undirected)
void addEdge(int u, int v)
{
    struct Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS cycle detection
int dfs(int v, int parent)
{
    visited[v] = 1;

    struct Node *temp = adj[v];
    while (temp)
    {
        int neighbor = temp->vertex;

        if (!visited[neighbor])
        {
            if (dfs(neighbor, v))
                return 1;
        }
        else if (neighbor != parent)
        {
            return 1; // cycle found
        }

        temp = temp->next;
    }

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
            if (dfs(i, -1))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}