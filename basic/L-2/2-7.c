#include <stdio.h>

int main() {
    int N, i;
    int fizzBuzz = 0, fizz = 0, buzz = 0, other = 0;

    if (scanf("%d", &N) != 1)
        return 1;

    for (i = 1; i <= N; i++) {
        if (i % 15 == 0)              // divisible by both
            fizzBuzz++;
        else if (i % 3 == 0)          // divisible by 3
            fizz++;
        else if (i % 5 == 0)          // divisible by 5
            buzz++;
        else
            other++;
    }

    printf("Count FizzBuzz (by 15): %d\n", fizzBuzz);
    printf("Count Fizz (by 3 only): %d\n", fizz);
    printf("Count Buzz (by 5 only): %d\n", buzz);
    printf("Count Other: %d\n", other);

    return 0;
}
