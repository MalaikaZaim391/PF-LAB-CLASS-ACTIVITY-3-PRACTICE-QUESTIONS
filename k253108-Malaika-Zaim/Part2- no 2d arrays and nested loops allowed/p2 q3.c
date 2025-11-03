#include<stdio.h>
int main(){
	int pass[10], fail[10], i, marks, countpass=0, countfail=0;
	float sumpassed=0, sumfailed=0, avgpass, avgfail;
	printf("Enter quiz marks for 10 students. Enter -1 to stop:\n");
	for(i=0;i<10; i++){
		printf("Enter marks for student %d: ", i+1);
		scanf("%d", &marks);
		if(marks==-1){
			break;
		}
		if(marks>=5 && marks<=10){
			pass[countpass]=marks;
			sumpassed+=marks;
			countpass++;
		}else if(marks<5 && marks>=0){
			fail[countfail]=marks;
			sumfailed+=marks;
			countfail++;
		}
		else{
			printf("Invalid Input. Enter appropriate marks (betwwen 0-10)");
		}
	}
	printf("\n===Passed Students===\n");
	if(countpass>0){
		printf("Marks: ");
		for(i=0; i<countpass;i++){
			printf("%4d", pass[i]);
		}
		avgpass=sumpassed/countpass;
		printf("\nAverage: %.2f", avgpass);
	}else{
		printf("No passed students");
	}
	printf("\n\n===Failed Students===\n");
	if(countfail>0){
		printf("Marks: ");
		for(i=0; i<countfail;i++){
			printf("%4d", fail[i]);
		}
		avgfail = sumfailed / countfail;
		printf("\nAverage: %.2f", avgfail);
	}else{
		printf("No failed students");
	}
	
	return 0;
	
}
