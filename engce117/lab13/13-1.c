#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx)
{
    int i, j;

    int **table;
    table = (int**)malloc((n+1)*sizeof(int*));

    for(i = 0; i <= n; i++)
        table[i] = (int*)malloc((wx+1)*sizeof(int));

    for(i = 0; i <= n; i++)
        for(j = 0; j <= wx; j++)
            table[i][j] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= wx; j++)
        {
            table[i][j] = table[i-1][j];

            if(w[i-1] <= j)
            {
                int candidate = table[i-1][j-w[i-1]] + v[i-1];

                if(candidate > table[i][j])
                    table[i][j] = candidate;
            }
        }
    }

    int *choose = (int*)calloc(n,sizeof(int));

    i = n;
    j = wx;

    while(i > 0 && j >= 0)
    {
        if(table[i][j] != table[i-1][j])
        {
            choose[i-1] = 1;
            j = j - w[i-1];
        }

        i--;
    }

    return choose;
}