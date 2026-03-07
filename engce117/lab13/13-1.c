#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx);

int *KnapsackDP(int *w, int *v, int n, int wx)
{
    int **table;
    int i, j;

    table = (int**)malloc((n + 1) * sizeof(int*));
    for(i = 0; i <= n; i++)
        table[i] = (int*)malloc((wx + 1) * sizeof(int));

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= wx; j++)
        {
            if(i == 0 || j == 0)
                table[i][j] = 0;
            else
            {
                if(w[i-1] <= j)
                {
                    int take = v[i-1] + table[i-1][j - w[i-1]];
                    int skip = table[i-1][j];

                    table[i][j] = (take > skip) ? take : skip;
                }
                else
                    table[i][j] = table[i-1][j];
            }
        }
    }

    int *result = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        result[i] = 0;

    int remain = wx;

    for(i = n; i > 0; i--)
    {
        if(table[i][remain] != table[i-1][remain])
        {
            result[i-1] = 1;
            remain -= w[i-1];
        }
    }

    return result;
}

int main()
{
    int n = 5, wx = 11;

    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x;

    x = KnapsackDP(w, v, n, wx);

    for(int i = 0; i < n; i++)
        printf("%d", x[i]);

    return 0;
}