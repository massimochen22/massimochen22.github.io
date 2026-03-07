#include <stdio.h>
#include <string.h>
int main() {
    /* 32*32 bits */
        unsigned char str[128];
        printf("please enter the string \n");
        scanf("%[^\n]", str);
        unsigned int len = strlen(str);
        unsigned int j,i,zeros;
        unsigned char temp;
	zeros = 0;
        for (j=0; j<len; j++) {
                temp = str[j];
                for (i=0; i<8; i++) {
			if (((temp & 0x80)>>7) == 0){
				zeros++;		
			}
                        temp=temp<<1;
                }
        }
	printf("%u",zeros);
 
    return printf("\n");
}
