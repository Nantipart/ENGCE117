#include <stdio.h>

#define SIZE 5

// Function prototypes.
void sort_array_ascending(int array[], int size);
void print_array(int array[], int size);

int main() {
    int numbers[SIZE];
    int original_copy[SIZE];
    int i;

    printf("Enter %d integer numbers for sorting:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
        original_copy[i] = numbers[i]; // Keep original copy.
    }

    // Call function to sort the array.
    sort_array_ascending(numbers, SIZE);

    printf("\n--- ARRAY SORTING REPORT ---\n");
    
    printf("Original Array: ");
    print_array(original_copy, SIZE);

    printf("Sorted Array (Ascending): ");
    print_array(numbers, SIZE);

    return 0;
}

// Function to sort array in ascending order using nested loops.
void sort_array_ascending(int array[], int size) {
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            // Swap if current element is greater than the next comparison element.
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Helper function to print array elements.
void print_array(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}