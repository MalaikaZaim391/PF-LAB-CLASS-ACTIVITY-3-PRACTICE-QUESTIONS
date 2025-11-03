#include<stdio.h>
int main(){
	int array[5], i, temp;
	printf("Enter five integer elements:\n");
	for(i=0; i<5; i++){
		printf("Element [%d]: ", i+1);
		scanf("%d", &array[i]);
	}
	printf("original array: \n");
	for(i=0; i<5; i++){
		printf("%3d", array[i]);
	}
	temp=array[4];
	for(i=4; i>0; i--){
		array[i]=array[i-1];
	}
	array[0]=temp;
	printf("\narray after shift: \n");
	for(i=0; i<5; i++){
		printf("%3d", array[i]);
	}
	
	
	
	return 0;
}
