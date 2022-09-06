#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int index;
    FILE * stream;
    FILE * stream2;
    char c;
    unsigned int thevalue;
    stream = fopen("numbers.txt", "r");
    stream2 = fopen("numbers.bin", "rb");
    if(stream == NULL || stream2 == NULL )
    {
        perror("fopen");
    }
    printf("Input index: ");
    while (scanf("%d\n", &index) != EOF){
        printf("Integer saved in text file: ");
        int space = 1;
        while((c=fgetc(stream))!=EOF){
            if (c == ' ' ){
                space++;
            }
            if (space == index && c != ' '){
                printf("%c",c);
            }
        }
        printf("\n");
        printf("Integer saved in binary file: ");
        fseek(stream2 ,sizeof(int)*(index-1),SEEK_SET);
        fread(&thevalue,sizeof(int),1, stream2 );
        printf("%d\n",thevalue);
        rewind(stream); 
        rewind(stream2); 
        printf("Input index: ");

    }
    fclose(stream);
    fclose(stream2);

    return 0;
}