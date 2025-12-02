#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *memberCount);

int main() {
    int *resultSet; 
    int count = 0;

    resultSet = GetSet(&count);

    printf("Output: ");
    for(int i = 0; i < count; i++) {
        printf("%d ", resultSet[i]);
    }
    printf("\n");

    if (resultSet != NULL) {
        free(resultSet);
    }

    return 0;
}
int *GetSet(int *memberCount) {
    int *setArray;

    printf("Number of members: ");
    scanf("%d", memberCount);

    setArray = (int*) malloc(*memberCount * sizeof(int));

    if (setArray == NULL) {
        printf("Memory allocation error\n");
        exit(1); 
    }

    printf("Input values:\n");
    for (int k = 0; k < *memberCount; k++) {
        printf("Member %d: ", k + 1);
        scanf("%d", &setArray[k]);
    }

    return setArray;
}