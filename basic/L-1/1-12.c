#include <stdio.h>

int main() {
    int planCode;
    float dataUsage_GB, totalBill = 0.0;

    //---- read input
    if (scanf("%d %f", &planCode, &dataUsage_GB) != 2)
        return 1;

    if (planCode == 1) {                     
        //---- Basic Plan
        totalBill = 299;
        if (dataUsage_GB > 10)
            totalBill += 10 * (dataUsage_GB - 10);
    }
    else if (planCode == 2) {                
        //---- Premium Plan
        totalBill = 599;
        if (dataUsage_GB > 20)
            totalBill += 50 + 5 * (dataUsage_GB - 20);
    }
    else {
        printf("Invalid Plan Code\n");
        return 0;
    }

    printf("%.2f\n", totalBill);
    return 0; 
}
