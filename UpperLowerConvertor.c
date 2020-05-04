#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define MISSING_NAME 1
int main(int argc, const char* argv[]){
  int c, error_status;
  if(argc != 2){ //Changed command set at argv[1] instead of argv[1]
    fprintf(stderr, "Too many arguments: Use ./main command\n");
    exit(1);
  }

error_status = MISSING_NAME;
  if(strcmp(argv[1], "lower") == 0){
    error_status = SUCCESS;
      while((c = getchar()) != EOF)
        putchar(tolower(c));
  }
  if(strcmp(argv[1], "upper") == 0){
    error_status = SUCCESS;
      while((c = getchar()) != EOF)
        putchar(toupper(c));
  }
if(error_status == MISSING_NAME){
  fprintf(stderr, "Use a name invoker like \"upper\" or \"lower\"\n");
  exit(1);
}
  return 0;
}
