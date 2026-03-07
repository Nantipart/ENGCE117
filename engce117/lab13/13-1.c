#include <stdio.h>
#include <stdlib.h>

// Dynamic Programming Knapsack function
int *KnapsackDP(int *w, int *v, int n, int wx)
{
    int i, j;

    // DP table
    int dp[n+1][wx+1];

    for(i = 0; i <= n; i++)
        for(j = 0; j <= wx; j++)
            dp[i][j] = 0;

    // Build DP table
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= wx; j++)
        {
            if(w[i-1] <= j)
            {
                int take = v[i-1] + dp[i-1][j-w[i-1]];
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

    // result array
    int *x = (int*)calloc(n, sizeof(int));

    j = wx;

    // trace back solution
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