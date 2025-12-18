#include <stdio.h>

int main() {
    int total_numbers;
    int idx = 0;

    // 1. Receive the count of numbers (N).
    if (scanf("%d", &total_numbers) != 1) return 1;

    // 2. Declare variable length array.
    int arr_data[total_numbers];

    // 3. Input loop: Using 'while' instead of 'for'.
    while (idx < total_numbers) {
        if (scanf("%d", &arr_data[idx]) != 1) return 1;
        idx++;
    }

    // 4. Reverse output loop: Start from last index down to 0.
    idx = total_numbers - 1;
    while (idx >= 0) {
        printf("%d\n", arr_data[idx]);
        idx--;
    }

    return 0;
}