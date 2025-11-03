#include<stdio.h>
int main(){
	int array[10], i, min, max, difference;
	printf("Enter 10 integers:\n");
	for(i=0; i<10; i++){
		printf("\tInteger %d: ", i+1);
		scanf("%d", &array[i]);
	}
	max=array[0];
	min=array[0];
	for(i=1; i<10; i++){
		if(array[i]>max){
			max=array[i];
		}
		if(array[i]<max){
			min=array[i];
		}
	}
	difference=max-min;
	printf("\nGreatest number = %d", max);
	printf("\nSmallest number = %d", min);
	printf("\nDifference = %d", difference);
	
	return 0;
}
