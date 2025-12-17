#include <stdio.h>

int main() {
    int N, i;
    int countFizzBuzz = 0;
    int countFizz = 0;
    int countBuzz = 0;
    int countOther = 0;

    if (scanf("%d", &N) != 1)
        return 1;

    for (i = 1; i <= N; i++) {
        int div3 = (i % 3 == 0);
        int div5 = (i % 5 == 0);

        if (div3 && div5)
            countFizzBuzz++;
        else if (div3)
            countFizz++;
        else if (div5)
            countBuzz++;
        else
            countOther++;
    }

    printf("Count FizzBuzz (by 15): %d\n", countFizzBuzz);
    printf("Count Fizz (by 3 only): %d\n", countFizz);
    printf("Count Buzz (by 5 only): %d\n", countBuzz);
    printf("Count Other: %d\n", countOther);

    return 0;
}
