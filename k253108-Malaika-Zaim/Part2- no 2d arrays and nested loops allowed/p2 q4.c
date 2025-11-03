//all characters have int values if if we have a capital letter adding 32 will convwrt it to small
//and subtracting 32 will turn a lower case letter into uppercase
#include<stdio.h>
int main(){
	char string[250];
	int i;
	printf("Enter a sentence:\n\t");
	scanf("%[^\n]", string);
	printf("\nOriginal message:\n\t%s", string);
	for(i=0; string[i]!='\0'; i++){
		if(string[i]>='A' && string[i]<='Z'){
			string[i]=string[i]+32;
		}else if(string[i]>='a' && string[i]<='z'){
			string[i]=string[i]-32;
		}
	}
	printf("\nConverted message:\n\t%s", string);
	
	
	
	return 0;
}
