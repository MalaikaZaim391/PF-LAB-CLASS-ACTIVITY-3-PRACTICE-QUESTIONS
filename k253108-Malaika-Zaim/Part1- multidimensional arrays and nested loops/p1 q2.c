#include <stdio.h>
#define MAX 5
int determinant(int mat[MAX][MAX], int n) {
    int det=0;
    if (n==1)
        return mat[0][0];
    else if (n==2)
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    else if (n == 3)
        return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
             - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
             + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    else
        return 0; 
}
int main() {
    int A[MAX][MAX], n, m;
    int i, j, k;
    int zero = 1, identity = 1, diagonal = 1, scalar = 1;
    int upper = 1, lower = 1, symmetric = 1, skew = 1;
    int idempotent = 1, nilpotent = 1;
    printf("Enter number of rows (max 5): ");
    scanf("%d", &n);
    printf("Enter number of columns (max 5): ");
    scanf("%d", &m);
    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("\tElement at [%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\nMatrix entered:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }
    // Property checks
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (A[i][j] != 0) zero = 0;
            if (i != j && A[i][j] != 0) diagonal = 0;
            if (i != j && A[i][j] != 0) identity = 0;
            if (i != j && A[i][j] != 0) scalar = 0;
            if (i > j && A[i][j] != 0) upper = 0;
            if (i < j && A[i][j] != 0) lower = 0;
            if (i < n && j < m && A[i][j] != A[j][i]) symmetric = 0;
            if (i < n && j < m && A[i][j] != -A[j][i]) skew = 0;
        }
    }
    if (n == m) {
        // Identity check
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j && A[i][j] != 1) identity = 0;
                if (i != j && A[i][j] != 0) identity = 0;
            }
        }
        // Scalar check
        int diagVal = A[0][0];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j && A[i][j] != diagVal) scalar = 0;
                if (i != j && A[i][j] != 0) scalar = 0;
            }
        }
        // Idempotent (A² = A)
        int prod[MAX][MAX] = {0};
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    prod[i][j] += A[i][k] * A[k][j];
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (prod[i][j] != A[i][j]) idempotent = 0;
        // Nilpotent (A² = 0)
        nilpotent = 1;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (prod[i][j] != 0) nilpotent = 0;
    }
    printf("\n==== MATRIX TYPE ANALYSIS ====\n");
    if (n == m) printf("\tSquare Matrix\n");
    else printf("\tRectangular Matrix\n");
    if (zero) printf("\tZero Matrix / Null Matrix\n");
    if (n == 1) printf("\tRow Matrix\n");
    if (m == 1) printf("\tColumn Matrix\n");
    if (diagonal && n == m) printf("\tDiagonal Matrix\n");
    if (scalar && n == m) printf("\tScalar Matrix\n");
    if (identity && n == m) printf("\tIdentity Matrix\n");
    if (upper && n == m) printf("\tUpper Triangular Matrix\n");
    if (lower && n == m) printf("\tLower Triangular Matrix\n");
    if (symmetric && n == m) printf("\tSymmetric Matrix\n");
    if (skew && n == m) printf("\tSkew-Symmetric Matrix\n");
    if (idempotent && n == m) printf("\tIdempotent Matrix\n");
    if (nilpotent && n == m) printf("\tNilpotent Matrix\n");
    if (n == m && n <= 3) {
        int det = determinant(A, n);
        if (det == 0)
            printf("\tSingular Matrix (det = 0)\n");
        else
            printf("\tNon-Singular Matrix (det = %d)\n", det);
    }
    printf("==============================\n");



    return 0;
}

