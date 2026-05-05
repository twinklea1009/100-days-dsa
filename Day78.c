/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2) */
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

    int visited[100] = {0};
    int key[100];

    for (int i = 1; i <= n; i++)
    {
        key[i] = 1000000000;
    }

    key[1] = 0;
    int total = 0;

    for (int count = 1; count <= n; count++)
    {
        int u = -1;
        int min = 1000000000;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d", total);

    return 0;
}