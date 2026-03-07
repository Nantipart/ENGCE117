#include <stdio.h>
#include <stdlib.h>

#define INF 99999

int *Dijkstra(int *L, int n);

int *Dijkstra(int *L, int n)
{
    int *dist = (int*)malloc(n * sizeof(int));
    int *visited = (int*)calloc(n, sizeof(int));

    int i, j;

    for(i = 0; i < n; i++)
        dist[i] = L[i];

    visited[0] = 1;

    for(i = 1; i < n; i++)
    {
        int min = INF;
        int u = -1;

        for(j = 1; j < n; j++)
        {
            if(!visited[j] && dist[j] != -1 && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(j = 1; j < n; j++)
        {
            int w = L[u * n + j];

            if(w != -1 && !visited[j])
            {
                int newDist = dist[u] + w;

                if(dist[j] == -1 || newDist < dist[j])
                    dist[j] = newDist;
            }
        }
    }

    return dist;
}

int main()
{
    int n = 5;
    int i, j;

    int *graph = (int*)malloc(n * n * sizeof(int));

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            graph[i * n + j] = -1;

    graph[0 * n + 1] = 100;
    graph[0 * n + 2] = 80;
    graph[0 * n + 3] = 30;
    graph[0 * n + 4] = 10;

    graph[1 * n + 2] = 20;
    graph[3 * n + 1] = 20;

    graph[3 * n + 2] = 20;
    graph[4 * n + 3] = 10;

    int *d = Dijkstra(graph, n);

    for(i = 1; i < n; i++)
        printf("%d ", d[i]);

    return 0;
}