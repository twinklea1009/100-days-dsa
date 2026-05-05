/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED  */
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adj[100];
int visited[100];

// create node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// add edge (undirected)
void addEdge(int u, int v)
{
    struct Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS
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
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 1; i <= n; i++)
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

    // start DFS from node 1
    dfs(1);

    // check if all visited
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");
    return 0;
}