#include <stdio.h>

#define THRESHOLD 150.0

// Function to compute net damage
float calcNetDamage(int atk, int armor) {
    float reduction;

    if (armor >= 50)
        reduction = 0.40;
    else
        reduction = 0.20;

    return (atk * 10.0) * (1.0 - reduction);
}

int main() {
    int cases;
    int atkLevel, enemyLevel, armor;
    int count = 0;

    if (scanf("%d", &cases) != 1)
        return 1;

    while (count < cases) {
        float damage;

        if (scanf("%d %d %d", &atkLevel, &enemyLevel, &armor) != 3)
            break;

        damage = calcNetDamage(atkLevel, armor);

        if (damage >= THRESHOLD) {
            printf("SUCCESS! Net Damage: %.2f\n", damage);
        } else {
            printf("FAIL. Deficit: %.2f\n", THRESHOLD - damage);
        }

        count++;
    }

    return 0;
}
