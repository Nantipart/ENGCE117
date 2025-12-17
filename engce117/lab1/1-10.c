#include <stdio.h>

int main() {
    int clearanceLevel, age, isActive;

    // read input
    if (scanf("%d %d %d", &clearanceLevel, &age, &isActive) != 3)
        return 1;

    // check access
    if ((clearanceLevel == 3 && isActive == 1) ||
        (clearanceLevel == 2 && age >= 25 && isActive == 1))
        printf("Access Granted\n");
    else
        printf("Access Denied\n");

    return 0;
}
