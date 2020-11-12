#include <stdio.h>
#include <stdlib.h>
#define LIMITE 100

void usage(char *s) {
  printf("Usage : %s <entier> <limite>, <limite> <= 100\n", s);
  exit(-1);
}

int main (int argc, char *argv[]) {
  int n, i, limite;
  if (argc < 2) {
   printf("Usage : %s <entier> <limite>, <limite> <= 100\n",argv[0]);
  }
  n = atoi(argv[1]);
  if (argc > 2) {
    limite = atoi(argv[2]);
    printf("Table de %d:",n);
    for(i = 0; i < limite ; i++) {
      printf(" %d", i*n);
    }
  }
  printf("\n");
  exit(0);
}
