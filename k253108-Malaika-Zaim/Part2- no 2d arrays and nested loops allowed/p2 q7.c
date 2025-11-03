#include <stdio.h>
int main() {
    int array[10], seen[1000] = {0};
    int i;
    printf("Enter 10 integers:\n");
    for (i=0; i<10; i++) {
        printf("\tInteger %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("\n\nOriginal array (with duplicates):\n\t");
    for (i=0; i<10; i++) {
        printf("%3d", array[i]);
    }
    for (i=0; i<10; i++) {
        int val = array[i];
        if (seen[val + 500] == 1) {  
            array[i] = -1;           
        } else {
            seen[val + 500] = 1;     
        }
    }
    printf("\nUpdated array (duplicates replaced with -1):\n\t");
    for (i=0; i<10; i++) {
        printf("%3d", array[i]);
    }
    printf("\n");


    return 0;
}

