#include <stdio.h> 
#include <unistd.h> 
  
int main(int argc, char *argv[]) 
{
    int opt;
      
    // put ':' in the starting of the
    // string so that program can 
    //distinguish between '?' and ':' 
    while((opt = getopt(argc, argv, ":if:lr")) != -1) 
    { 
        switch(opt) 
        { 
            case 'i': 
            case 'l': 
            case 'r': 
                printf("option: %c\n", opt); 
                break; 
            case 'f': 
                printf("filename: %s\n", optarg); 
                break; 
            case ':': 
                printf("option %c needs a value\n", optopt); 
                break; 
            case '?': 
                printf("unknown option: %c\n", optopt);
                break; 
            default:
                printf("extra arguments: %s\n", argv[optind]);
        } 
    } 
      
    // optind is for the extra arguments
    // which are not parsed
    // for(; optind < argc; optind++){     
    //     printf("extra arguments: %s\n", argv[optind]); 
    // }
      
    return 0;
}