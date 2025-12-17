#include <stdio.h>

int main() {
    int score;
    int A = 0, B = 0, C = 0, D = 0, F = 0;

    while (1) {
        if (scanf("%d", &score) != 1)
            return 1;

        if (score == -1)             // sentinel value
            break;

        if (score >= 80)
            A++;
        else if (score >= 70)
            B++;
        else if (score >= 60)
            C++;
        else if (score >= 50)
            D++;
        else
            F++;
    }

    printf("Grade A Count: %d\n", A);
    printf("Grade B Count: %d\n", B);
    printf("Grade C Count: %d\n", C);
    printf("Grade D Count: %d\n", D);
    printf("Grade F Count: %d\n", F);

    return 0;
}
