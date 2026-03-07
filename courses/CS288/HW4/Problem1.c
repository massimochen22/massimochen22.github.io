#include <stdio.h>
int power(int num,int expon)
{
    int z;
    int number = 1;
    for (z = 0; z < expon; ++z)
        number *= num;
    return(number);
}
int main() {
	unsigned int value, range_i, range_f, i, j, mask, fin_value, temp;
	printf("please enter the value range following this format 'value index_ini index_final' for example '789 2 8'\n");
	scanf("%d %d %d", &value, &range_i, &range_f);
	fin_value = 0;
	temp = range_f - range_i;
    for (j=0; j<32; j++) {
	    if ((31-j) >= range_i && (31-j)<=range_f){
			mask = 1<<((31-j));
			fin_value = ((value & mask)>>(31-j)) * power( 2, temp) + fin_value;   
			printf("%u", (value & mask)>>(31-j));
			temp--;
	    }
	    else{
			mask = 0<<((31-j));
	    }
    }
	printf(" int value: %u", fin_value);   
    return printf("\n");
}

