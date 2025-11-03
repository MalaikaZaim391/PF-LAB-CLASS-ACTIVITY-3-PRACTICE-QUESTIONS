#include<stdio.h>
int main(){
	int A[3][3], B[3][3], result[3][3];
	int row1,col1,row2,col2, i,j,k;
	printf("Enter rows for Matrix A (max 3): ");
    scanf("%d", &row1);
    printf("Enter columns for Matrix A (max 3): ");
    scanf("%d", &col1);
    printf("Enter rows for Matrix A (max 3): ");
    scanf("%d", &row2);
    printf("Enter columns for Matrix A (max 3): ");
    scanf("%d", &col2);
    getchar();
    if (col1!=row2) {
        printf("Matrix multiplication not possible! Columns of A must equal rows of B.\n");
        return 0;
    }
    printf("\nEnter elements of Matrix A:\n");
    for (i=0; i<row1; i++) {
        for (j=0; j<col1; j++) {
        	printf("\tElement [%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nEnter elements of Matrix B:\n");
    for (i=0; i<row2; i++) {
        for (j=0; j<col2; j++) {
        	printf("\tElement [%d][%d]: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }
	for(i=0; i<row1; i++) {
	        for(j=0; j<col2; j++) {
	            result[i][j] = 0;
	        }
	    }
    for(i=0; i<row1; i++) {
        for(j=0; j<col2; j++) {
            for(k=0; k<col1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\nMatrix A:\n");
    for(i=0; i<row1; i++) {
        for(j=0; j<col1; j++) {
            printf("\t%4d", A[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix B:\n");
    for(i=0; i<row2; i++) {
        for(j=0; j<col2; j++) {
            printf("\t%4d", B[i][j]);
        }
        printf("\n");
    }
    printf("\nResult (A x B):\n");
    for (i=0; i<row1; i++) {
        for (j=0; j<col2; j++) {
            printf("\t%4d", result[i][j]);
        }
        printf("\n");
    }
    return 0;

}
