/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[100][100];
    int adjSize[100] = {0};
    int indegree[100] = {0};

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        indegree[v]++;
    }

    int queue[100];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int result[100];
    int count = 0;

    while (front < rear)
    {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < adjSize[node]; i++)
        {
            int nbr = adj[node][i];
            indegree[nbr]--;

            if (indegree[nbr] == 0)
                queue[rear++] = nbr;
        }
    }

    if (count != n)
    {
        printf("Cycle exists, topological sort not possible");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("%d ", result[i]);
        }
    }

    return 0;
}