/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex */
#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

// Graph structure
struct Graph
{
    int n;
    struct Node **adjList;
};

// Create new node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph *createGraph(int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->n = n;

    graph->adjList = (struct Node **)malloc(n * sizeof(struct Node *));

    for (int i = 0; i < n; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph *graph, int u, int v)
{
    // u -> v
    struct Node *newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    // For undirected graph, uncomment below:
    // newNode = createNode(u);
    // newNode->next = graph->adjList[v];
    // graph->adjList[v] = newNode;
}

// Print adjacency list
void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->n; i++)
    {
        printf("%d: ", i);
        struct Node *temp = graph->adjList[i];

        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph *graph = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);

    return 0;
}