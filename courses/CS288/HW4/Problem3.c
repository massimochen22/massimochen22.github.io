#include <stdio.h>
#include <string.h>
int power(int num,int expon){
    int z;
    int number = 1;
    for (z = 0; z < expon; ++z)
        number *= num;
    return(number);
}
int main() {
	unsigned char str[128]; 
	printf("please enter the string \n");
	scanf("%[^\n]", str);
	unsigned int len = strlen(str);
	unsigned int j,i;
	unsigned char temp, fin_value; 
        for (j=0; j<len; j++) {
		temp = str[j];
		fin_value = 0;
		for (i=0; i<8; i++) {
			if (i>3){
				fin_value = ((temp ^ 0x80)>>7)* power( 2, (7-i)) + fin_value; 
			}
			else{
				fin_value = ((temp & 0x80)>>7)* power( 2, (7-i)) + fin_value ;
			}
			temp=temp<<1;
		}
		printf("%c",fin_value);
    }
    return printf("\n");
}
