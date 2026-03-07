#include <stdio.h>
#include <stdlib.h>



int main( int argc, char ** argv, char * envp[] )
{
	int index = 0;

	while(envp[index]){
	  printf("envp[%d] = \"%s\"\n", index, envp[index]);
    index++;
	} 
	printf("Number of environment vars = %d\n", index );
	exit( 0 );
}
