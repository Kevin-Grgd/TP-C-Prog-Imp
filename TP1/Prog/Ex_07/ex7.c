#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void usage(char *s) {
  printf("Usage : %s <entier positif> \n", s);
  exit(-1);
}

int main(int argc, char *argv[]) {
  int n,i,factorielle;
    
  if (argc < 2) {
    usage(argv[0]);
  }

  n = atoi(argv[1]);
  factorielle = 1;
  i = 1;

  if (n <= 0){
    usage(argv[0]);
  }
  
  while (i <= n && factorielle <= INT_MAX) {
    factorielle = factorielle * i;
    i++;
  }
  
  printf("Le factorielle de %d est : %d \n", n,factorielle);
  exit(EXIT_SUCCESS);
}
