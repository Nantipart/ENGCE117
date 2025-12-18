#include <stdio.h>

#define DAYS 7

int main() {
    int temp[DAYS];
    int highest;
    int day;

    // Read temperatures and track highest value
    for (day = 0; day < DAYS; day++) {
        scanf("%d", &temp[day]);

        if (day == 0 || temp[day] > highest) {
            highest = temp[day];
        }
    }

    // Output report
    printf("=== TEMPERATURE SUMMARY ===\n");
    printf("Temperatures: ");

    for (day = 0; day < DAYS; day++) {
        printf("%d ", temp[day]);
    }

    printf("\nHighest Temperature: %d C\n", highest);

    // Weather condition check
    if (highest >= 35) {
        printf("Weather is HOT!\n");
    } else {
        printf("Weather is MODERATE.\n");
    }

    return 0;
}
