#include <stdio.h>
int main() {
    char temp[250], result[250];
    int position = 0, i;
    printf("Enter a string (no letters will be stored):\n\t");
    while (1) {
        if (scanf("%*[A-Za-z]") == EOF) break;
        if (scanf("%[^A-Za-z\n]", temp) == 1) {
            for (i = 0; temp[i] != '\0'; i++) {
                result[position++] = temp[i];
            }
        }
        int ch = getchar();
        if (ch == '\n' || ch == EOF) break;
        ungetc(ch, stdin); 
    }
    result[position] = '\0';
    printf("All non-alphabet characters:\n\t%s\n", result);
    return 0;
}


//#include <stdio.h>
//int main() {
//    char string[250], result[250];
//    int i, j = 0;
//    printf("Enter a string (letters will be removed):\n\t");
//    scanf("%[^\n]", str);  
//    for (i = 0; string[i]!='\0'; i++) {
//        if (!((string[i]>='A' && string[i]<='Z') || (string[i]>='a' && string[i]<='z'))) {
//            result[j++]=string[i];
//        }
//    }
//
//    result[j] = '\0';  // null terminate
//    printf("All non-alphabet characters:\n\t%s\n", result);
//
//    return 0;
//}
