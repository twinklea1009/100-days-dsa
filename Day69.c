/*Problem: Given weighted graph with non-negative edges,
compute shortest path from source using priority queue.*/
#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int vertex;
    int weight;
    struct Edge *next;
};

struct Edge *adj[100];

struct Edge *createEdge(int v, int w)
{
    struct Edge *newEdge = malloc(sizeof(struct Edge));
    newEdge->vertex = v;
    newEdge->weight = w;
    newEdge->next = NULL;
    return newEdge;
}

void addEdge(int u, int v, int w)
{
    struct Edge *newEdge = createEdge(v, w);
    newEdge->next = adj[u];
    adj[u] = newEdge;
}

int getMinVertex(int dist[], int visited[], int n)
{
    int min = 1000000000; // large value instead of INF
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int n, int source)
{
    int dist[100], visited[100] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = 1000000000; // initialize with large value

    dist[source] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = getMinVertex(dist, visited, n);

        if (u == -1)
            break;

        visited[u] = 1;

        struct Edge *temp = adj[u];

        while (temp != NULL)
        {
            int v = temp->vertex;
            int w = temp->weight;

            if (!visited[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }

    // print result
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == 1000000000)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}