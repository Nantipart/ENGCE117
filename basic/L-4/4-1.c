#include <stdio.h>

// Function to read numbers and print in reverse
void readReverse(int n) {
    int x;
    if (n == 0)
        return;

    scanf("%d", &x);
    readReverse(n - 1);
    printf("%d\n", x);
}

int main() {
    int N;

    if (scanf("%d", &N) != 1)
        return 1;

    readReverse(N);

    return 0;
}
