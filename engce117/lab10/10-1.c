#include <stdio.h>

long SumLoop(int);
long SumRecur(int);

int main()
{
    printf("SumLoop(n) = %ld\n", SumLoop(10));
    printf("SumRecur(n) = %ld\n", SumRecur(10));
    return 0;
}

long SumLoop(int n)
{
    long sum = 0;
    int i = 1;

    while(i <= n)
    {
        sum = sum + i;
        i++;
    }

    return sum;
}

long SumRecur(int n)
{
    if(n == 0)
        return 0;

    return n + SumRecur(n - 1);
}