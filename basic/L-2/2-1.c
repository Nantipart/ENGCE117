#include <stdio.h>

int main() {
    int N, i;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    // Initialize counter
    i = 0; 

    // Continue looping as long as i is less than N
    while (i < N) {
        printf("Hello Loop!\n");
        i++; 
        // Increment the counter
    }

    return 0;
}