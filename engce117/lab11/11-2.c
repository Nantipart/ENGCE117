#include <stdio.h>

void mergesort(int t[], int k);
void merge(int *u, int m, int *v, int n, int *t);

void mergesort(int t[], int k)
{
    if(k < 2)
        return;

    int leftSize = k / 2;
    int rightSize = k - leftSize;

    mergesort(t, leftSize);
    mergesort(t + leftSize, rightSize);

    int buffer[k];

    merge(t, leftSize, t + leftSize, rightSize, buffer);

    int index = 0;
    while(index < k)
    {
        t[index] = buffer[index];
        index++;
    }
}

void merge(int *u, int m, int *v, int n, int *t)
{
    int a = 0;
    int b = 0;
    int c = 0;

    while(a < m || b < n)
    {
        if(a < m && (b >= n || u[a] <= v[b]))
        {
            t[c++] = u[a++];
        }
        else
        {
            t[c++] = v[b++];
        }
    }
}

int main()
{
    int data[7] = {4, 6, 1, 2, 5, 1, 8};
    int n = 7;

    mergesort(data, n);

    for(int i = 0; i < n; i++)
        printf("%d ", data[i]);

    return 0;
}