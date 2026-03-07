#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void radix_sort (unsigned long*a,int size){
  unsigned int i,j,arr_of_1_index,arr_of_0_index;
  unsigned long arr_of_1[size], arr_of_0[size],mask;
  for (i =0; i<64; i++){
    arr_of_1_index = 0;
    arr_of_0_index = 0;
    mask = 1<<i;
    for (j = 0 ; j<size;j++){
      if ((mask & a[j])>>i ==0){
        arr_of_0[arr_of_0_index] = a[j];
        arr_of_0_index++;
      }
      else{
        arr_of_1[arr_of_1_index] = a[j];
        arr_of_1_index++;
      }
    }

    unsigned int xyz, xy;
    for (xy=0; xy<arr_of_0_index;xy++){
      unsigned long temp1 = arr_of_0[xy];
      a[xy] = temp1;
    }

    for (xyz=0; xyz<arr_of_1_index;xyz++){
      unsigned long temp2 = arr_of_1[xyz];
      a[xy] = temp2;
      xy++;
    }
  }
}

int main(){
  unsigned long array1[10] = {1212,41241,514214,32524,123124,532412,3254235,1231243,23523542,13312};
  radix_sort(array1,10);
  for (int i = 0; i<10; i++){
    printf("%lu \n",array1[i]);
  }
}