#include <stdio.h>
#include <stdlib.h>

void usage(char *s) {
  printf("Usage : %s <entier h>, entier supérieur strict  à 0 \n",s);
  exit(EXIT_FAILURE);
}

int main (int argc, char *argv[]) {
  int h,i,j;
  int x = 1;

  if (argc < 2) {
    usage(argv[0]);
  }

  h = atoi(argv[1]);

  for (i = 0; i < h; i++) {
    for (j = 0; j < x; j++) {
      printf("*");
    }
    printf("\n");
    x++;
  }
  printf("\n");
  exit(EXIT_SUCCESS);
}
    
