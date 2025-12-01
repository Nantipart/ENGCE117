#include <stdio.h>
#include <stdlib.h>

int *GetSet( int * );

int main() {
    int *data, num;
    data = GetSet( &num );

    printf("Output: ");
    for(int i=0; i<num; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    free(data); 

    return 0;
}

int *GetSet(int *num) {
    int *arr;
    printf("Number of members: "); 
    scanf("%d", num);

    arr = (int*) malloc(*num * sizeof(int));

    printf("Input values:\n");
    for(int i = 0; i < *num; i++) {
        printf("Member %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    return arr;
}