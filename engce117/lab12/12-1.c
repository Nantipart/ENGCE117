#include <stdio.h>
#include <stdlib.h>

#define INF 99999

int *Dijkstra(int *L, int n);

int *Dijkstra(int *L, int n)
{
    int *distance = (int*)malloc(n * sizeof(int));
    int *used = (int*)calloc(n, sizeof(int));

    int i, j;

    for(i = 0; i < n; i++)
        distance[i] = L[i];

    used[0] = 1;

    for(i = 1; i < n; i++)
    {
        int best = INF;
        int current = -1;

        for(j = 1; j < n; j++)
        {
            if(!used[j] && distance[j] != -1 && distance[j] < best)
            {
                best = distance[j];
                current = j;
            }
        }

        if(current == -1)
            break;

        used[current] = 1;

        for(j = 1; j < n; j++)
        {
            int edge = L[current * n + j];

            if(edge != -1 && !used[j])
            {
                int candidate = distance[current] + edge;

                if(distance[j] == -1 || candidate < distance[j])
                    distance[j] = candidate;
            }
        }
    }

    return distance;
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

    int *result = Dijkstra(graph, n);

    for(i = 1; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}