#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void linkPointer(int ***dest, int **src);
void showState(const char *msg, int **ptr);

int main() {
    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));
    int **ref;

    *x = 10;
    *y = 20;

    // Point ref to x
    linkPointer(&ref, &x);
    showState("After linking to x", ref);

    // Point ref to y
    linkPointer(&ref, &y);
    showState("After linking to y", ref);

    free(x);
    free(y);

    return 0;
}

// Assign double pointer using triple pointer
void linkPointer(int ***dest, int **src) {
    *dest = src;
}

// Display pointer relationship
void showState(const char *msg, int **ptr) {
    printf("%s\n", msg);
    printf("Value: %d\n", **ptr);
    printf("*ptr (address stored): %p\n", (void *)*ptr);
    printf("ptr (double pointer): %p\n\n", (void *)ptr);
}
