#include <stdio.h>
#include <stdlib.h>

void GetSet(int **data, int *num);

int main() {
    int *data;
    int num;

    GetSet(&data, &num);

    printf("\nMembers of the received set :\n");
    for(int i = 0; i < num; i++){
        printf("%d ", data[i]);
    }

    free(data);
    return 0;
}

void GetSet(int **data, int *num) {
    printf("Number of members : ");
    scanf("%d", num);

    *data = malloc(*num * sizeof(int));

    printf("Enter values ​​one member at a time :\n");
    for(int i = 0; i < *num; i++){
        printf("Member %d: ", i+1);
        scanf("%d", &(*data)[i]);
    }
}