#include <stdio.h> 
#include <string.h>
int main(int argc, char** argv) {
    unsigned char *p;
    printf( "argv    | "); 
    p = &argv;
    for (int i=7; i>=0; i--)
        printf("%02hhx ", *(p+i));
    printf("| %p\n\n\n", &argv);

    for (int y=0; y<argc; y++){
        printf("argv[%u]  | ", y);
        p = &argv[y];
        for (int i=7; i>=0; i--)
            printf("%02hhx ", *(p+i));
        printf(" | %p", &argv[y]);
        printf("\n");
    }
    printf("\n\n\n");
    unsigned long *q;
    for (int z=0; z<argc; z++){
        if (z==(argc-1)){
            int x = strlen(argv[z]);
            p = &argv[z][x]; 
        }
        else{
            p = &argv[z][0];    
        }

        q = (unsigned long *) &p;
        p = (*q)&0xFFFFFFFFFFFFFFF8;
        printf("| ");
        for (int j=7; j>=0; j--){
            if (p[j] == NULL)
                printf("%02hhx(\\0) ",p[j]);
            else
                printf("%02hhx(%c) ", p[j],p[j]);
        }
        printf(" | ");
        printf("%p\n", p);
    }
}