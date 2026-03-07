#include <stdio.h>
int main() {
        unsigned int value, j, mask, index_f, index_i, count, maxCount;
        printf("please enter the value \n");
        scanf("%d", &value);
		count = 0;
		maxCount = 0;
        for (j=0; j<32; j++) {
			mask = 1<<((31-j));
			if ((value & mask)>>(31-j) == 1){
				count = count+1;
			} 
			else{
				if(maxCount < count){
					maxCount = count;	
					index_f= 31-j;
				}
				count = 0;
			}
			printf("%u", (value & mask)>>(31-j));
			if(maxCount < count){
				index_f= 31-j;
				maxCount = count;
			}
        }
	index_i = index_f + maxCount - 1;
	printf("\n%u '1's from index %u to index %u", maxCount, index_f, index_i);
    return printf("\n");
}

