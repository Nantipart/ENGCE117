#include <stdio.h>

#define LIMIT 5 

// Function Prototype 
int calculate_sum(int arr[], int size);

int main() {
    int data[LIMIT];      
    int result_sum;
    float final_avg;
    int k;               
    printf("Input %d integers numbers:\n", LIMIT);
    for (k = 0; k < LIMIT; k++) {
        printf("Number %d: ", k + 1);
        scanf("%d", &data[k]);
    }

    result_sum = calculate_sum(data, LIMIT);

    final_avg = (float)result_sum / LIMIT;

    // Display final report.
    printf("\n=== ARRAY AVERAGE REPORT ===\n");
    printf("Recorded Numbers: { ");
    for (k = 0; k < LIMIT; k++) {
        printf("%d", data[k]);
        if (k < LIMIT - 1) { 
            printf(", ");
        }
    }
    printf(" }\n");

    printf("Total Sum : %d\n", result_sum);
    printf("Average   : %.2f\n", final_avg);

    return 0;
}

// Function Definition
int calculate_sum(int arr[], int size) {
    int total = 0;
    int idx = 0;

    // Iterate through array to accumulate sum.
    while (idx < size) {
        total += arr[idx];
        idx++;
    }

    return total;
}