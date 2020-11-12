#include <stdio.h>
#include <stdlib.h>

void usage(char *s) {
  printf("Usage : %s <entier>, entier supérieur strict  à 0 \n",s);
  exit(EXIT_FAILURE);
}

int main (int argc, char *argv[]) {
  int i,n;
  
  if (argc < 2) {
    usage(argv[0]);
  }

  n = atoi(argv[1]);

  for (i = 0; i < n; i++) {
    printf("*");
  }
  printf("\n");
  exit(EXIT_SUCCESS);
}
