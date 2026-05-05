/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.  */
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[100][100] = {0};

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    scanf("%d", &source);

    int dist[100], visited[100] = {0};

    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1000000000;
    }

    dist[source] = 0;

    for (int count = 1; count <= n; count++)
    {
        int u = -1;
        int min = 1000000000;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }

    return 0;
}