#include <stdio.h>
#include <stdlib.h>

// Function to get and print values
void GetSet(int *data, int *num);

int main() {
    int num;

    printf("Enter the number of members: ");
    scanf("%d", &num);  // Get number of members

    int data[num];  // Create an array to store members

    GetSet(data, &num); // Call function to input and display values

    return 0;
}

// Function to input and print values
void GetSet(int *data, int *num) {
    printf("Enter values for each member:\n");

    for (int i = 0; i < *num; i++) {
        printf("Member %d: ", i + 1);
        scanf("%d", &data[i]);  // Input each member's value
    }

    printf("\nValues entered:\n");

    for (int i = 0; i < *num; i++) {
        printf("%d ", data[i]);  // Print all values
    }
    printf("\n");
}