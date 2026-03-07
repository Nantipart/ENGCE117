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
    long total = 0;

    while(n > 0)
    {
        total += n;
        n--;
    }

    return total;
}

long SumRecur(int n)
{
    if(n <= 1)
        return n;

    int mid = n / 2;

    return SumRecur(mid) + SumRecur(n) - SumRecur(mid - 1);
}