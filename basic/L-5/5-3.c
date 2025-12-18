#include <stdio.h>

#define SIZE 5

// Function prototype declaration.
int calculate_sum(int array[], int size);

int main() {
    int numbers[SIZE];
    int total_sum;
    float average;
    int i;

    // Receive 5 integers from user.
    printf("Enter %d integer numbers:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Call function to calculate total sum.
    total_sum = calculate_sum(numbers, SIZE);

    // Calculate average value.
    average = (float)total_sum / SIZE;

    // Display final report.
    printf("\n--- ARRAY AVERAGE REPORT ---\n");
    printf("Recorded Numbers: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("Total Sum: %d\n", total_sum);
    printf("Average: %.2f\n", average);

    return 0;
}

// Function to calculate sum of array elements.
int calculate_sum(int array[], int size) {
    int sum = 0;
    int i;
    
    // Iterate through array to accumulate sum.
    for (i = 0; i < size; i++) {
        sum += array[i];
    }
    
    return sum;
}