#include <stdio.h>

int main() {
    int level, age, active;
    int granted = 0;   // access flag

    if (scanf("%d %d %d", &level, &age, &active) != 3)
        return 1;

    if (active) {
        if (level == 3)
            granted = 1;
        else if (level == 2 && age >= 25)
            granted = 1;
    }

    printf(granted ? "Access Granted\n" : "Access Denied\n");
    return 0;
}
