#include <stdio.h> 
int main() {
        unsigned int count = 0;
        scanf("%d", &count);
        unsigned int arr[count], i,j, i2,val, arr_of_1[count], arr_of_1_index, arr_of_0[count],arr_of_0_index,mask; 
        for (i=0; i<count; i++) {
            scanf("%d", &val);
            arr[i] = val;
        }
        for (i2=0; i2<32; i2++) {
            arr_of_0_index = 0;
            arr_of_1_index = 0;
            mask = 1<<i2;
            for (j=0; j<count; j++) {
                if ((mask&arr[j])>>i2 == 0){
                    arr_of_0[arr_of_0_index] = arr[j];
                    arr_of_0_index++;
                }
                else{
                    arr_of_1[arr_of_1_index] = arr[j];
                    arr_of_1_index++;
                }       
            }
            unsigned int xyz,xy;
            for (xy=0; xy<arr_of_0_index; xy++) {
                unsigned int temp1 = arr_of_0[xy];
                arr[xy] = temp1;
            }
            for (xyz=0; xyz<arr_of_1_index; xyz++) {
                unsigned int temp2 = arr_of_1[xyz];
                arr[xy] = temp2;
                xy++;
            }
        }
        int z = 0;
        for (z=0; z<count; z++) {
            printf("%d \n", arr[z]);
        }
    return printf("\n");
}