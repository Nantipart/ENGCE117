#include <stdio.h>
#include <stdlib.h>

// Function to get the size of the set
int *GetSet(int *num);

int main()
{
    int *data, num;

    // Call GetSet to get the number of elements
    data = GetSet(&num);

    // Get elements of the set from the user
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < num; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &data[i]);
    }

    // Print the elements (optional)
    printf("The elements of the set are:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    // No need to free memory here as requested

    return 0;
}

// Function to allocate memory for the set and get its size
int *GetSet(int *num)
{
    // Get the number of elements in the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", num);

    // Allocate memory for the set
    int *set = (int *)malloc((*num) * sizeof(int));

    // Return the pointer to the allocated memory
    return set;
}