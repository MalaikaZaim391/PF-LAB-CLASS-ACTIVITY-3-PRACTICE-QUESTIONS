#include <stdio.h>
int main() {
    int array[3][3][3];
    int i, j, k, layer1, layer2;
    int identical;
    printf("Enter elements for the 3x3x3 matrix set:\n");
    for (i = 0; i < 3; i++) {
        printf("\n====Enter elements for Layer %d====\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("\tElement at[%d][%d][%d] = ", i, j, k);
                scanf("%d", &array[i][j][k]);
            }
        }
    }
    printf("\n==============================\n");
    printf("Displaying All Layers:\n");
    for (i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%4d", array[i][j][k]);
            }
            printf("\n");
        }
    }
    printf("\n==============================\n");
    printf("Layer Similarity Analysis:\n");
    for (layer1 = 0; layer1 < 3; layer1++) {
        for (layer2 = layer1 + 1; layer2 < 3; layer2++) {
            identical = 1; // assume identical until proven otherwise
            printf("\nComparing Layer %d and Layer %d:\n", layer1 + 1, layer2 + 1);
            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    if (array[layer1][j][k] != array[layer2][j][k]) {
                        printf("\tDifference at position [%d][%d]: %d != %d\n",
                               j, k, array[layer1][j][k], array[layer2][j][k]);
                        identical = 0;
                    }
                }
            }
            if (identical)
                printf("\tLayer %d and Layer %d are IDENTICAL.\n", layer1 + 1, layer2 + 1);
            else
                printf("\tLayer %d and Layer %d are DISTINCT.\n", layer1 + 1, layer2 + 1);
        }
    }
    printf("\n==============================\n");
    printf("Similarity Report Completed.\n");



    return 0;
}

