#include <stdio.h>
#include <stdlib.h>

void usage(char *s) {
  printf("Usage : %s <entier> <limite>, <limite> <= 100\n",s);
  exit(-1);
}

int main (int argc, char *argv[]) {
  int n,i,limite;
  if (argc<2) {
    printf("Usage : %s <entier> <limite>, <limite> <= 100\n",argv[0]);
  }

  n = atoi(argv[1]);
  limite = atoi(argv[2]);
  if (limite > 100) {
    usage(argv[0]);
  }
  printf("Table de %d: ",n);
  i=1;
  while (i < limite) {
    printf("%d ",i*n);
    i++;
  }
  printf("\n");
  exit(EXIT_SUCCESS);
}
