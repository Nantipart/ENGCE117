#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx);

int *KnapsackGreedy(int *w, int *v, int n, int wx)
{
    int i, j;

    int *choose = (int*)calloc(n, sizeof(int));
    float *score = (float*)malloc(n * sizeof(float));

    for(i = 0; i < n; i++)
        score[i] = (float)v[i] / w[i];

    for(i = 0; i < n-1; i++)
    {
        int best = i;

        for(j = i+1; j < n; j++)
        {
            if(score[j] > score[best])
                best = j;
        }

        if(best != i)
        {
            float ts = score[i];
            score[i] = score[best];
            score[best] = ts;

            int tw = w[i];
            w[i] = w[best];
            w[best] = tw;

            int tv = v[i];
            v[i] = v[best];
            v[best] = tv;
        }
    }

    int capacity = 0;

    for(i = 0; i < n; i++)
    {
        if(capacity + w[i] <= wx)
        {
            choose[i] = 1;
            capacity += w[i];
        }
    }

    return choose;
}

int main()
{
    int n = 5, wx = 11;

    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackGreedy(w, v, n, wx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    return 0;
}