#include <stdio.h>
#include <stdlib.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x)
{
    int bestValue = 0;
    int bestSet[n];

    for(int t = 0; t < n; t++)
        bestSet[t] = 0;

    for(int k = i; k < n; k++)
    {
        if(w[k] <= wx)
        {
            int childSet[n];

            for(int j = 0; j < n; j++)
                childSet[j] = 0;

            int value = v[k] + KnapsackBT(w, v, n, wx - w[k], k + 1, childSet);

            if(value > bestValue)
            {
                bestValue = value;

                for(int j = 0; j < n; j++)
                    bestSet[j] = childSet[j];

                bestSet[k] = 1;
            }
        }
    }

    for(int j = 0; j < n; j++)
        x[j] = bestSet[j];

    return bestValue;
}

int main()
{
    int n = 5, wx = 11;
    int w[5] = {1,2,5,6,7};
    int v[5] = {1,6,18,22,28};

    int *x, vx;

    x = (int*)malloc(n * sizeof(int));

    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d\n", vx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}