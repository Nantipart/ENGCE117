#include <stdio.h>

enum ResultStatus {
    LOW_CHANCE = 0,
    HIGH_CHANCE = 1
};

void evaluateOdds(int outs, float *prob, int *result);

int main() {
    int outs = 10;
    float probability = 0.0f;
    int status;

    evaluateOdds(outs, &probability, &status);

    printf("\n--- POKER ODDS ANALYSIS (2 Cards Remaining) ---\n");
    printf("Outs Count        : %d\n", outs);
    printf("Winning Chance   : %.2f%%\n", probability);
    printf("Assessment       : %s\n",
           (status == HIGH_CHANCE) ? "HIGH Win Probability" : "LOW Win Probability");

    return 0;
}

void evaluateOdds(int outs, float *prob, int *result) {
    *prob = outs * 4.0f;   // Rule of 4

    *result = (*prob >= 30.0f) ? HIGH_CHANCE : LOW_CHANCE;
}
