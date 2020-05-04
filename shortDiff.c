#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lineCheck(char * l, char * d, int lineNumber){
  if(strcmp(l,d) != 0){
  printf("[File 1]%d >> %s\n", lineNumber, l);
  printf("[File 2]%d >> %s\n", lineNumber, d);
  }
}

int main(int argc, char* argv[]){
  FILE *fp1, *fp2;
  char line1[BUFSIZ], line2[BUFSIZ];
  int i;

  if(argc != 3){
    fprintf(stderr, "Not the right amount of arguments: ./main file1 file2");
    exit(1);
  }

  fp1 = fopen(argv[1], "r");
  if(fp1 == NULL){
    fprintf(stderr, "Can't open file %s\n", argv[1]);
    exit(1);
  }
  fp2 = fopen(argv[2], "r");
  if(fp2 == NULL){
    fprintf(stderr, "Can't open file %s\n", argv[2]);
    exit(1);
  }
  i = 0;
  while(fgets(line1, BUFSIZ, fp1) != NULL && fgets(line2, BUFSIZ, fp2) != NULL){
    lineCheck(line1, line2, i);
    ++i;
  }
  return 0;
}
