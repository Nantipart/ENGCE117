#include <stdio.h>

int main() {
    int N;
    int score;
    int sumPass = 0;
    int failCount = 0;
    int i = 0;

    // Receive number of scores
    if (scanf("%d", &N) != 1)
        return 1;

    // Read and process each score immediately
    while (i < N) {
        if (scanf("%d", &score) != 1)
            return 1;

        if (score >= 50)
            sumPass += score;
        else
            failCount++;

        i++;
    }

    printf("Passing Scores Sum: %d\n", sumPass);
    printf("Failing Students Count: %d\n", failCount);

    return 0;
}
