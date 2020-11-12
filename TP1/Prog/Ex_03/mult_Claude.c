#include <stdio.h>
#include <stdlib.h>

#define LIMITE 100

void usage(char *s) {
  printf("Usage : %s <entier> <limite>, <limite> <= 100\n", s);
  exit(-1);
}

int main (int argc, char *argv[]) {
  int n, i, limite;
  limite = atoi(argv[2]);
  if (argc < 2) {
    usage(argv[0]);
  }
  
  n = atoi(argv[1]);
  
  if (argc > 2) {
    if (limite > LIMITE) {
      usage(argv[0]);
    }
  }
  
  printf("Table de %d:",n);
  
  for(i=limite;i>0;i--) {
    printf(" %d", i*n);
  }
  printf("\n");
  exit(0);
}
