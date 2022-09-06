#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap( char **element1Ptr, char **element2Ptr){
  char *temp = *element1Ptr;
  *element1Ptr = *element2Ptr;
  *element2Ptr = temp;
}
void bubble(char* work[], int size)
{
  int pass, count;
  for ( pass = 1; pass < size; pass++)
    for ( count = 0; count < size - 1; count++ )
      if ( strcmp(work[count], work[count+1]) > 0)
        swap( &work[count], &work[count+1] );
}

int main( int argc, char ** argv, char * envp[] )
{
	int index = 0;
    int index2 = 0;
	while(envp[index]){
        index++;
	} 
    char * list[index];
    while(envp[index2]){
        char* temp = strtok(envp[index2], "=");
        list[index2] = temp;
        temp = strtok(NULL, "=");
        // int strl = strlen(list[index2]);
        // envp[index2][strl] = '=';  
    index2++;
	} 
    int index3 = 0;
    bubble( envp, index);
	while(envp[index3]){
    // int strl = strlen(list[index2]);
    // envp[index2][strl] = '=';  
        int strl = strlen(envp[index3]);
        envp[index3][strl] = '=';  
	    printf("%s\n", envp[index3]);
        index3++;
	} 

	exit( 0 );
}
