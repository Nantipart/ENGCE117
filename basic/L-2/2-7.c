#include <stdio.h>

int main() {
    int N;
    int fizzBuzz, fizz, buzz, other;

    if (scanf("%d", &N) != 1)
        return 1;

    fizzBuzz = N / 15;            // divisible by 3 and 5
    fizz = N / 3 - fizzBuzz;      // divisible by 3 only
    buzz = N / 5 - fizzBuzz;      // divisible by 5 only
    other = N - (fizzBuzz + fizz + buzz);

    printf("Count FizzBuzz (by 15): %d\n", fizzBuzz);
    printf("Count Fizz (by 3 only): %d\n", fizz);
    printf("Count Buzz (by 5 only): %d\n", buzz);
    printf("Count Other: %d\n", other);

    return 0;
}
