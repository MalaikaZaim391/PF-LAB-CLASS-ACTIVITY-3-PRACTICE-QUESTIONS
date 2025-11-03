#include<stdio.h>
int main(){
	int array[10], i, searchnum, countnum=0;
	printf("Enter 10 integer elements:\n");
	for(i=0; i<10; i++){
		printf("Element [%d]: ", i+1);
		scanf("%d", &array[i]);
	}
	printf("original array: \n");
	for(i=0; i<10; i++){
		printf("%3d", array[i]);
	}
	printf("\nEnter the integer number you want to search: ");
	scanf("%d", &searchnum);
	for(i=0; i<10; i++){
		if(array[i]==searchnum){
			countnum++;
		}
	}
	if(countnum>0){
		printf("\nSearched number: %d\nFound in array: %d times\n", searchnum, countnum);
	}else{
		printf("\nNumber not found!\n");
	}
	
	
	return 0;
}
