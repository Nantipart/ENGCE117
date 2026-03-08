#include <stdio.h>
#include <stdlib.h>

/*
   Knapsack Backtracking
   w  = weight array
   v  = value array
   n  = number of items
   wx = remaining capacity
   i  = current item index
   x  = selected item result
*/
int KnapsackBT(int *weight, int *value, int n, int capacity, int startIndex, int *result)
{
    int bestValue = 0;
    int bestChoice[n];

    for(int index = 0; index < n; index++)
        bestChoice[index] = 0;

    for(int item = startIndex; item < n; item++)
    {
        /* Check if current item can be placed in knapsack */
        if(weight[item] > capacity)
            continue;

        int childChoice[n];

        for(int k = 0; k < n; k++)
            childChoice[k] = 0;

        /* Recursive exploration of remaining items */
        int currentValue = value[item] +
                           KnapsackBT(weight,
                                      value,
                                      n,
                                      capacity - weight[item],
                                      item + 1,
                                      childChoice);

        /* Update best solution if better value found */
        if(currentValue > bestValue)
        {
            bestValue = currentValue;

            for(int k = 0; k < n; k++)
                bestChoice[k] = childChoice[k];

            bestChoice[item] = 1;
        }
    }

    /* Copy best result to output array */
    for(int k = 0; k < n; k++)
        result[k] = bestChoice[k];

    return bestValue;
}

int main()
{
    int numberOfItems = 5;
    int maxWeight = 11;

    int weight[5] = {1,2,5,6,7};
    int value[5]  = {1,6,18,22,28};

    int *selectedItems;
    int bestValue;

    selectedItems = (int*)malloc(numberOfItems * sizeof(int));

    /* Run Knapsack Backtracking */
    bestValue = KnapsackBT(weight,
                           value,
                           numberOfItems,
                           maxWeight,
                           0,
                           selectedItems);

    printf("Value = %d\n", bestValue);

    for(int i = 0; i < numberOfItems; i++)
        printf("%d ", selectedItems[i]);

    free(selectedItems);

    return 0;
}