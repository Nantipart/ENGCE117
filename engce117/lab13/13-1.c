#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx);

int *KnapsackDP(int *w, int *v, int n, int wx)
{
    int r, c;

    int **dp = (int**)malloc((n+1) * sizeof(int*));
    for(r = 0; r <= n; r++)
        dp[r] = (int*)calloc(wx+1, sizeof(int));

    for(r = 1; r <= n; r++)
    {
        for(c = 0; c <= wx; c++)
        {
            dp[r][c] = dp[r-1][c];

            if(c >= w[r-1])
            {
                int val = v[r-1] + dp[r-1][c - w[r-1]];
                if(val > dp[r][c])
                    dp[r][c] = val;
            }
        }
    }

    int *choose = (int*)calloc(n, sizeof(int));

    int capacity = wx;

    for(r = n; r > 0; r--)
    {
        if(dp[r][capacity] != dp[r-1][capacity])
        {
            choose[r-1] = 1;
            capacity -= w[r-1];
        }
    }

    return choose;
}

int main()
{
    int n = 5, wx = 11;

    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackDP(w, v, n, wx);

    for(int i = 0; i < n; i++)
        printf("%d", x[i]);

    return 0;
}