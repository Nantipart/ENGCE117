#include <stdio.h>

int binarySearch(int arr[], int size, int target);

int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 7};
    int length = 6;
    int key = 5;

    int result = binarySearch(numbers, length, key);

    if(result >= 0)
        printf("Value %d found at index %d\n", key, result);
    else
        printf("Value not found\n");

    return 0;
}

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
        int middle = (start + end) / 2;

        if(arr[middle] == target)
            return middle;

        if(target > arr[middle])
            start = middle + 1;
        else
            end = middle - 1;
    }

    return -1;
}