#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int opt;
  while((opt = getopt(argc, argv, ":cduf:s:")) != -1) {
    switch(opt) {
      case 'c':
      case 'd':
      case 'u':
        printf("option: %c\n", opt); break;
      case 'f':
        printf("filename: %s\n", optarg); break;
      case 's':
        printf("type: %s\n", optarg); break;
      case ':':
        printf("option %c needs a value\n", optopt); break;
      case '?':
        printf("unknown option: %c\n", optopt); break;
    }
  }
  
  for(; optind < argc; optind++)
    printf("argument: %s\n", argv[optind]);

}
