#include <stdio.h>

// Helper functions
int isUpper(char c) { return (c >= 'A' && c <= 'Z'); }
int isLower(char c) { return (c >= 'a' && c <= 'z'); }
int isDigit(char c) { return (c >= '0' && c <= '9'); }

int main() {
    char text[101];
    char *p;

    int upper = 0, lower = 0, digit = 0, other = 0;

    if (scanf("%100s", text) != 1)
        return 1;

    // Use pointer to traverse string
    for (p = text; *p != '\0'; p++) {
        if (isUpper(*p))
            upper++;
        else if (isLower(*p))
            lower++;
        else if (isDigit(*p))
            digit++;
        else
            other++;
    }

    printf("Uppercase: %d\n", upper);
    printf("Lowercase: %d\n", lower);
    printf("Digits: %d\n", digit);
    printf("Special/other: %d\n", other);

    return 0;
}
