#include <stdio.h>

#define SIZE 5

enum UpdateStatus {
    NOT_FOUND = 0,
    FOUND = 1
};

void replace_value(int arr[], int size, int target, int replacement, int *status);
void show_array(int arr[], int size);

int main() {
    int numbers[SIZE];
    int search_val, new_val;
    int status = NOT_FOUND;

    printf("Enter %d integer elements:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("\nSearch value: ");
    scanf("%d", &search_val);

    printf("New value: ");
    scanf("%d", &new_val);

    printf("\n--- ARRAY UPDATE REPORT ---\n");
    printf("Before update: ");
    show_array(numbers, SIZE);

    replace_value(numbers, SIZE, search_val, new_val, &status);

    printf("After update : ");
    show_array(numbers, SIZE);

    printf("Status: %s\n",
           (status == FOUND) ? "Update SUCCESSFUL." : "Update FAILED.");

    return 0;
}

void show_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void replace_value(int arr[], int size, int target, int replacement, int *status) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            arr[i] = replacement;
            *status = FOUND;
            break;  // Stop after first replacement
        }
    }
}
