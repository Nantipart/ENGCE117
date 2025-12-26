#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    /* Get the value N */
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    /* Reserve dynamic memory */
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    /* Receive N numerical values. */
    int *p = arr;
    int count = n;
    while (count--) {
        if (scanf("%d", p) != 1) {
            free(arr);
            return 1;
        }
        p++;
    }

    /* Show results back */
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }

    free(arr);
    return 0;
}
