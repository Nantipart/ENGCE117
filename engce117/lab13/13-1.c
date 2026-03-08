#include <stdio.h>
#include <stdlib.h>

/* Dynamic Programming Knapsack */
int *KnapsackDP(int *weight, int *value, int n, int capacity)
{
    int i, j;

    /* create DP table */
    int **K = (int**)malloc((n + 1) * sizeof(int*));
    for(i = 0; i <= n; i++)
        K[i] = (int*)malloc((capacity + 1) * sizeof(int));

    /* initialize first row and column */
    for(i = 0; i <= n; i++)
        K[i][0] = 0;

    for(j = 0; j <= capacity; j++)
        K[0][j] = 0;

    /* fill table */
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j <= capacity; j++)
        {
            int notChoose = K[i-1][j];
            int choose = notChoose;

            if(weight[i-1] <= j)
            {
                int temp = value[i-1] + K[i-1][j - weight[i-1]];
                if(temp > choose)
                    choose = temp;
            }

            K[i][j] = choose;
        }
    }

    /* determine selected items */
    int *selected = (int*)calloc(n, sizeof(int));
    int capLeft = capacity;

    for(i = n; i > 0; i--)
    {
        if(K[i][capLeft] > K[i-1][capLeft])
        {
            selected[i-1] = 1;
            capLeft = capLeft - weight[i-1];
        }
    }

    return selected;
}

int main()
{
    int n = 5;
    int wx = 11;

    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackDP(w, v, n, wx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}