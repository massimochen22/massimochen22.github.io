#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int numtasks, taskid, numworkers;
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
    MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
    numworkers = numtasks-1;
    int index = 0, i; 
    char str [128];
    FILE * stream2;
    unsigned int thevalue;

    if (taskid==0){    
        printf("please enter the pathname \n");
        scanf("%[^\n]", str);
    }
    MPI_Bcast(str, 128, MPI_CHAR, 0, MPI_COMM_WORLD);
    stream2 = fopen(str, "rb");
    if(stream2 == NULL )
    {
        perror("fopen");
    }
    while (1){
        if (fread(&thevalue,sizeof(int),1, stream2 ) < 1 )
        {
            break;
        }
        index++;
    }
    int *array = (int*)malloc(index * sizeof(int));
    int *countArray = (int*)malloc(1000 * sizeof(int));
    fclose(stream2);
    stream2 = fopen(str, "rb");
    if(stream2 == NULL )
    {
        perror("fopen");
    }
    while (1){
        if ( fread(&thevalue,sizeof(int),1, stream2 ) < 1 )
        {
            break;
        }
        array[i] = thevalue;
        i++;
    }
    fclose(stream2);
    int subIndex = index/numtasks;
    int *sub_array = (int*)malloc(subIndex * sizeof(int));
    int *sub_count = (int*)malloc(1000 * sizeof(int));
    MPI_Scatter(array, subIndex ,MPI_INT, sub_array, subIndex , MPI_INT, 0, MPI_COMM_WORLD);
	
    for (int id=0; id< 1000;id++){
	sub_count[id] = 0;
    }    

    for (int id=0; id< 1000;id++){
        for (int id2=0; id2<subIndex; id2++){
            if (id == sub_array[id2] ){
                sub_count[id]++;
            }
        }
    }
	
     int global_int;
     for (int id=0; id< 1000;id++){
        MPI_Reduce(&sub_count[id], &global_int, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
        countArray[id] = global_int;
     }

    // for (int id=0; id< 1000;id++){
//	   printf("number %d appears %d times\n",id,sub_count[id]);
  //   }

     if (taskid==0){  
        int value;
        FILE * stream;
        stream = fopen(str, "wb");
        if(stream == NULL)
        {
            perror("fopen");
        }
        for (int id=0; id< 1000;id++){
            for (int curr = 0; curr<countArray[id];curr++){
                fwrite(&id, sizeof id, 1, stream);
            }
        }
         ///dasdsadadsdasdasdadasda
        fclose(stream);

    }
    
  MPI_Finalize();
 
    return 0;
}


