#include<stdio.h>
int main(){
	int matrix[3][3], transpose[3][3];
	int i,j;
	printf("Enter the elements of 3x3 matrix\n\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("Element at [%d][%d]: ", i+1,j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\nThe matrix is: \n");
	for(i=0; i<3;i++){
		for(j=0; j<3; j++){
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}
//	transpose here
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			transpose[j][i]=matrix[i][j];
		}			
	}
	printf("The transpose is: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%3d", transpose[i][j]);
		}			
		printf("\n");
	}
//	determinant of 3x3 matrix is det=a(ei-fh)-b(di-fg)+c(dh-eg) determinant here:
	int det;
	det = matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1])
    - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0])
    + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);
    printf("Determinant is: \n");
    printf("%3d", det);
//    cofactor here: cofactor is C[i][j] = (-1)^(i+j) * minor(i,j) where minor(i,j) is determinant of 2×2 matrix after removing row i and column j
	int cofactor[3][3];
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			int sub[2][2], r=0,k, c, n;
			for(k=0; k<3; k++){
				if(k==i){
					continue;
				}
				c=0;
				for(n=0; n<3; n++){
					if(n==j){ continue;
					}
					sub[r][c]=matrix[k][n];
					c++;
				}
				r++;
			}
			int minor=sub[0][0]*sub[1][1]-sub[0][1]*sub[1][0];
			cofactor[i][j]=((i+j)%2==0 ? 1: -1) *minor;
		}
	}
    printf("\nCofactor Matrix: \n");
    for(i=0; i<3; i++){
    	for(j=0; j<3; j++){
    		printf("%3d", cofactor[i][j]);
		}
		printf("\n");
	}
//    adjoint here - transpose of cofactor
	int adjoint[3][3];
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			adjoint[i][j]=cofactor[j][i];
		}
	}
	printf("\nAdjoint Matrix:\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%3d", adjoint[i][j]);
		}
		printf("\n");
	}
//		inverse here - formula is 1/det * adjoint(A)
	float inverse[3][3];
	if(det==0){
		printf("\nInverse does not exist (determinant is 0).\n");
	} else {
		for(i=0; i<3; i++){
			for(j=0; j<3; j++){
				inverse[i][j]=(float)adjoint[i][j]/det;
			}
		}
	}
	printf("\nInverse Matrix: \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%.2f\t", inverse[i][j]);
		}
		printf("\n");
	}
    
	return 0;
}
