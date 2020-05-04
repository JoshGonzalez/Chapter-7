#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXLINES 10
#define TRUE 1
#define FALSE 0

void printfile(const char* filename){
  FILE *fp;
  int linecount, c, pagenumber = 1, newpage = TRUE;

if(filename == NULL){
  fprintf(stderr, "Incorrect file formant");
  exit(1);
}

  if ((fp = fopen(filename, "r")) != NULL) {
    while ((c = fgetc(fp)) != EOF) {
      if (newpage) {
        printf("[%s] page %d starts\n", filename, pagenumber);
        newpage = FALSE;
        linecount = 1;
      }
      putchar(c);
      ++linecount;
      if (c == '\n' && linecount > MAXLINES) {
        printf("[%s] page %d ends\n", filename, pagenumber);
        putchar('\n');
        newpage = TRUE;
        pagenumber++;
      }
    }
    if (!newpage) {
      putchar('\n');
      printf("[%s] page %d ends\n", filename, pagenumber);
    }
    fclose(fp);
  }
}

int main(int argc, const char* argv[])
{
  if (argc < 2) {
    fprintf(stderr, "no files specified\n");
    exit(1);
  }
  for (int i = 1; i < argc; i++) {
    printfile(argv[i]);
  }
  return 0;
}
