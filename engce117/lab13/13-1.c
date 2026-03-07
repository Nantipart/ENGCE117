#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx)
{
    int i, j;

    int **dp = (int**)malloc((n+1) * sizeof(int*));
    for(i = 0; i <= n; i++)
        dp[i] = (int*)calloc(wx+1, sizeof(int));

    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= wx; j++)
        {
            if(w[i-1] <= j)
            {
                int a = v[i-1] + dp[i-1][j-w[i-1]];
                int b = dp[i-1][j];

                if(a > b)
                    dp[i][j] = a;
                else
                    dp[i][j] = b;
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    int *x = (int*)calloc(n, sizeof(int));

    j = wx;
    for(i = n; i > 0; i--)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            x[i-1] = 1;
            j = j - w[i-1];
        }
    }

    return x;
}

int main()
{
    int n = 5, wx = 11;
    int w[5] = {1,2,5,6,7};
    int v[5] = {1,6,18,22,28};

    int *x;

    x = KnapsackDP(w,v,n,wx);

    for(int i=0;i<n;i++)
        printf("%d ",x[i]);

    return 0;
}