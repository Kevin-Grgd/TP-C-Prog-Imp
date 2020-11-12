#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int n, i, somme;
  if (argc < 2) {
    printf("Usage : %s <entier>\n" ,argv[0]);
    exit(-1);
      }
  n = atoi(argv[1]);
  somme = 0;
  for(i = 1; i < n; i++) {
    if(n % i == 0) {
      somme += i;
    }
  }
  if(somme == n) {
    printf("%d est parfait\n", n);
  } else {
    printf("%d n'est pas parfait\n", n);
  }
  printf("\n");
  exit(EXIT_SUCCESS);
}
