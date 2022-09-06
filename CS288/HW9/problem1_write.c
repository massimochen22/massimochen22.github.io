#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int value;
    FILE * stream;
    FILE * stream2;
    stream = fopen("numbers.txt", "w");
    stream2 = fopen("numbers.bin", "wb");
    int count = 1;
    if(stream == NULL || stream2 == NULL )
    {
        perror("fopen");
    }

    printf("Input data %d : ",count);
    while(scanf("%d\n", &value) != EOF){
        char str[1000];
        sprintf(str, "%d", value);
        char space[]= " ";
        strcat(str,space);
        fputs(str, stream);
        fwrite(&value, sizeof value, 1, stream2);
        count++;
        printf("Input data %d : ",count);
    }
    fclose(stream);
    fclose(stream2);

    return 0;
}