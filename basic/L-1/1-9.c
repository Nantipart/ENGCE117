#include <stdio.h>

int main() {
    int region;
    float mass;
    float cost = 0.0;

    if( scanf("%d %f", &region, &mass) != 2 ) {
        return 1;
    }

    switch( region ) {
        case 1:
            cost = (mass <= 5.0) ? 50.0 : 80.0;
            break;

        case 2:
            cost = (mass <= 10.0) ? 150.0 : 250.0;
            break;

        case 3:
            cost = 500.0;
            break;

        default:
            printf("Invalid Zone Code\n");
            return 1;
    }

    printf("%.2f\n", cost);
    return 0;
}