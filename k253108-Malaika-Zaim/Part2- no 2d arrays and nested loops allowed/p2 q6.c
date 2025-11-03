#include<stdio.h>
int main(){
	char string[250], temp;
	int i, vowels=0, consonants=0;
	printf("Enter a word/sentence:\n\t ");
	scanf("%[^\n]", string);
	for(i=0; string[i]!='\0'; i++){
		temp=string[i];
		if(temp=='A'||temp=='a'||temp=='E'||temp=='e'||temp=='I'||temp=='i'
		||temp=='O'||temp=='o'||temp=='U'||temp=='u'){
			vowels++;
		}else if((temp<='Z' && temp>='A')||(temp<='z' && temp>='a')){
			consonants++;
		}
	}
	printf("\nYour string: %s", string);
	printf("\nNumber of vowels: %d", vowels);
	printf("\nNumber of consonants: %d", consonants);
	
	
	return 0;
	
}
