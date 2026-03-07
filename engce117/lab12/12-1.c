#include <stdio.h>
#include <stdlib.h>

int *Dijkstra(int *L, int n);

int *Dijkstra(int *L, int n)
{
    int *dist = (int*)malloc(n * sizeof(int));
    int *visited = (int*)malloc(n * sizeof(int));

    int i, j;

    for(i = 0; i < n; i++)
    {
        dist[i] = L[i];
        visited[i] = 0;
    }

    visited[0] = 1;

    for(i = 1; i < n; i++)
    {
        int min = 9999;
        int node = -1;

        for(j = 1; j < n; j++)
        {
            if(!visited[j] && dist[j] >= 0 && dist[j] < min)
            {
                min = dist[j];
                node = j;
            }
        }

        if(node == -1)
            break;

        visited[node] = 1;

        for(j = 1; j < n; j++)
        {
            int weight = L[node * n + j];

            if(weight != -1 && !visited[j])
            {
                int newDist = dist[node] + weight;

                if(dist[j] == -1 || newDist < dist[j])
                    dist[j] = newDist;
            }
        }
    }

    return dist;
}

int main()
{
    int n = 5, i = 0, j = 0, *d, *g;

    g = (int*)malloc(n * n * sizeof(int));

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100; 
    g[0 * n + 2] = 80;
    g[0 * n + 3] = 30; 
    g[0 * n + 4] = 10;

    g[1 * n + 2] = 20; 
    g[3 * n + 1] = 20;

    g[3 * n + 2] = 20; 
    g[4 * n + 3] = 10;

    d = Dijkstra(g, n);

    for(i = 0; i < n - 1; i++)
        printf("%d ", d[i + 1]);

    return 0;
}