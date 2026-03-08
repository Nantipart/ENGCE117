#include <stdio.h>
#include <stdlib.h>

/* Dynamic Programming Knapsack */
int *KnapsackDP(int *w, int *val, int n, int maxW)
{
    int i, j;

    /* allocate DP table */
    int **dp = (int**)malloc((n + 1) * sizeof(int*));
    for(i = 0; i <= n; i++)
    {
        dp[i] = (int*)malloc((maxW + 1) * sizeof(int));
    }

    /* initialize table */
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= maxW; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = 0;
        }
    }

    /* fill dp table */
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= maxW; j++)
        {
            if(w[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                int take = val[i-1] + dp[i-1][j - w[i-1]];
                int skip = dp[i-1][j];

                if(take > skip)
                    dp[i][j] = take;
                else
                    dp[i][j] = skip;
            }
        }
    }

    /* determine selected items */
    int *result = (int*)calloc(n, sizeof(int));
    int remain = maxW;

    for(i = n; i > 0; i--)
    {
        if(dp[i][remain] != dp[i-1][remain])
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
        printf("%d ", x[i]);

    return 0;
}