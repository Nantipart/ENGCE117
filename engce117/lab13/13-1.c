#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx)
{
    int i, j;

    int dp[n+1][wx+1];

    for(i = 0; i <= n; i++)
        for(j = 0; j <= wx; j++)
            dp[i][j] = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= wx; j++)
        {
            if(w[i-1] <= j)
            {
                int take = v[i-1] + dp[i-1][j - w[i-1]];
                int nottake = dp[i-1][j];

                if(take > nottake)
                    dp[i][j] = take;
                else
                    dp[i][j] = nottake;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int *x = (int*)calloc(n, sizeof(int));

    j = wx;
    for(i = n; i > 0; i--)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            x[i-1] = 1;
            j -= w[i-1];
        }
    }

    return x;
}