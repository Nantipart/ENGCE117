#include <stdio.h>
#include <stdlib.h>

/* Dynamic Programming Knapsack */
int *KnapsackDP(int *w, int *v, int n, int maxW)
{
    int i, j;

    /* allocate DP matrix */
    int **dp = (int**)malloc((n + 1) * sizeof(int*));
    for(i = 0; i <= n; i++)
        dp[i] = (int*)malloc((maxW + 1) * sizeof(int));

    /* set initial values */
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= maxW; j++)
        {
            dp[i][j] = 0;
        }
    }

    /* build DP table */
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= maxW; j++)
        {
            int withoutItem = dp[i-1][j];
            int withItem = 0;

            if(w[i-1] <= j)
                withItem = v[i-1] + dp[i-1][j - w[i-1]];

            if(withItem > withoutItem)
                dp[i][j] = withItem;
            else
                dp[i][j] = withoutItem;
        }
    }

    /* track selected items */
    int *ans = (int*)calloc(n, sizeof(int));
    int remain = maxW;

    for(i = n; i > 0; i--)
    {
        if(dp[i][remain] != dp[i-1][remain])
        {
            ans[i-1] = 1;
            remain -= w[i-1];
        }
    }

    return ans;
}

int main()
{
    int n = 5, wx = 11;

    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackDP(w, v, n, wx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}