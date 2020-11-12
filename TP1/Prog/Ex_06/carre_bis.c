#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int i = 0;
  do {
    printf("Le carre de %d est : %d \n", i , i * i);
    i++;
  }
  while (i < 10);
  exit(0);
}
