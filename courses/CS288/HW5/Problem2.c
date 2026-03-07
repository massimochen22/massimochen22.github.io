#include <stdio.h> 
int main() {
        unsigned int count = 0;
        scanf("%d", &count);
        float val, arr_all[count],arr_of_0[count],arr_of_1[count];
        unsigned int i, j,i2,arr_of_0_index,arr_of_1_index,mask;
        for (i=0; i<count; i++) {
            scanf("%f", &val);
            arr_all[i] = val;
        }
        for (i2=0; i2<32; i2++) {
            arr_of_0_index = 0;
            arr_of_1_index = 0;
            mask = 1<<i2;
            if (i2==31){
                for (j=0; j<count; j++) {
                    unsigned int *p = (unsigned int *) &arr_all[j];
                    if ((mask & *p) >>i2 == 0){
                        arr_of_1[arr_of_1_index] = arr_all[j];
                        arr_of_1_index++;
                    }
                    else{
                        arr_of_0[arr_of_0_index] = arr_all[j];
                        arr_of_0_index++;
                    }     
                }
            }
            else{
                for (j=0; j<count; j++) {
                    unsigned int *p = (unsigned int *) &arr_all[j];
                    if ((mask & *p) >>i2 == 0){
                        arr_of_0[arr_of_0_index] = arr_all[j];
                        arr_of_0_index++;
                    }
                    else{
                        arr_of_1[arr_of_1_index] = arr_all[j];
                        arr_of_1_index++;
                    }     
                }
            }
            unsigned int xyz,xy;
            if (i2<31){
                for (xy=0; xy<arr_of_0_index; xy++) {
                    float temp1 = arr_of_0[xy];
                    arr_all[xy] = temp1;
                }
                for (xyz=0; xyz<arr_of_1_index; xyz++) {
                    float temp2 = arr_of_1[xyz];
                    arr_all[xy] = temp2;
                    xy++;
                }
            }
            else{
                for (xy=0; xy<arr_of_0_index; xy++) {
                    float temp1 = arr_of_0[arr_of_0_index-xy-1];
                    printf("%f \n", temp1);
                }
                for (xyz=0; xyz<arr_of_1_index; xyz++) {
                    float temp2 = arr_of_1[xyz];
                    printf("%f \n", temp2);
                }   
            }   
        }
    return 0;
}