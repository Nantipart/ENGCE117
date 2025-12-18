#include <stdio.h>

#define DAYS 7   // Number of days

int main() {
    int daily_temp[DAYS];   // Array to store temperatures
    int max_temp;
    int i;

    // 1. Input temperatures for 7 days
    for (i = 0; i < DAYS; i++) {
        scanf("%d", &daily_temp[i]);
    }

    // 2. Find maximum temperature
    max_temp = daily_temp[0];
    for (i = 1; i < DAYS; i++) {
        if (daily_temp[i] > max_temp) {
            max_temp = daily_temp[i];
        }
    }

    // 3. Display report
    printf("--- DAILY TEMPERATURE REPORT ---\n");
    printf("Recorded Temperatures (C): ");
    for (i = 0; i < DAYS; i++) {
        printf("%d ", daily_temp[i]);
    }
    printf("\n");

    printf("Maximum Temperature Found: %d C\n", max_temp);

    // 4. Weather summary
    if (max_temp >= 35) {
        printf("Weather is HOT!\n");
    } else {
        printf("Weather is MODERATE.\n");
    }

    return 0;
}
