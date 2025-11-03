#include <stdio.h>
int main() {
    int array[3][3][3];
    int layerSum[3] = {0}; 
    int totalSum = 0;      
    int i, j, k;
    printf("Enter elements for the 3x3x3 arrayay:\n");
    for (i = 0; i < 3; i++) {
        printf("\n====Enter elements for Layer %d====\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("\tElement at [%d][%d][%d] = ", i, j, k);
                scanf("%d", &array[i][j][k]);
            }
        }
    }
    printf("\n===================================\n");
    printf("Displaying 3D Array Layer by Layer:\n");
    for (i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%4d", array[i][j][k]);
                layerSum[i] += array[i][j][k];
                totalSum += array[i][j][k];
            }
            printf("\n");
        }
        printf("Sum of Layer %d = %d\n", i + 1, layerSum[i]);
    }
    printf("\n===================================\n");
    printf("Overall Total of All Elements = %d\n", totalSum);
    printf("\nAnalytical Insights:\n");
    int maxLayer = 0, minLayer = 0;
    for (i = 1; i < 3; i++) {
        if (layerSum[i] > layerSum[maxLayer])
            maxLayer = i;
        if (layerSum[i] < layerSum[minLayer])
            minLayer = i;
    }
    printf("\tLayer %d has the highest sum (%d)\n", maxLayer + 1, layerSum[maxLayer]);
    printf("\tLayer %d has the lowest sum (%d)\n", minLayer + 1, layerSum[minLayer]);
    
	
	return 0;
}

