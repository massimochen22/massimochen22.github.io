#include <stdio.h>
#include <stdlib.h> 
int main (int argc, char ** argv) {
    unsigned int count = atoi(argv[1]);
    //int rows=2, min_columns=4, val=1;
    switch(count) {
        case 0:
            return 0;
        case 1:
            printf("1\n");
            return 0;
        case 2:
            printf("1\n1 1\n");
            return 0;
    }
    int val=1;
    int **matrix = (int **) malloc(count * sizeof(int *));
    matrix[0] = (int *) malloc(1 * sizeof(int));
    matrix[1] = (int *) malloc(2 * sizeof(int));
    matrix[0][0] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 1;

    for (int i = 2; i < count; i++){ 
        matrix[i] = (int *) malloc((i+1) * sizeof(int));
        for (int j = 0; j < i+1; j++){ 
            if (j == 0 || j == i){
                matrix[i][j] = 1;
            }
            else{
                matrix[i][j] = (matrix[i-1][j]) + (matrix[i-1][j-1]);
            }
        }
    }

    for (int k = 0; k < count; k++){ 
        for (int z = 0; z < k+1; z++){ 
            printf("%u ",matrix[k][z]);
        }
        printf("\n");
        free(matrix[k]);
    }
 
 free(matrix);
}
