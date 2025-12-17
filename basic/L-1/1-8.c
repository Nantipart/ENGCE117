#include <stdio.h>

int main() {
    int dayCode, hour;
    int isWorkday = 0;

    scanf("%d %d", &dayCode, &hour);

    switch (dayCode) {
        case 1: case 2: case 3: case 4: case 5:
            isWorkday = 1;
            break;
        case 6: case 7:
            printf("Weekend Relax Mode\n");
            return 0;
        default:
            printf("Invalid Day Code\n");
            return 0;
    }

    if (isWorkday && hour >= 8 && hour <= 17)
        printf("System Running (Workday)\n");
    else
        printf("System Idle (Off-hours)\n");

    return 0;
}
