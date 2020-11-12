#include <stdio.h>
#include <stdlib.h>

void usage(char *s) {
  printf("Usage : %s <entier m> <entier n>, entiers supérieur strict  à 0 \n",s);
  exit(EXIT_FAILURE);
}

int main (int argc, char *argv[]) {
  int n,m,i,j;

  if (argc < 3) {
    usage(argv[0]);
  }

  m = atoi(argv[1]);
  n = atoi(argv[2]);
  
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("*");
    }
    printf("\n");
  }

  printf("\n");
  exit(EXIT_SUCCESS);
}
