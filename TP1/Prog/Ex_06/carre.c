#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int i = 0;
  while (i < 10) {
      printf("Le carre de %d est : %d \n", i , i * i);
      i++;
    }
  exit(0);
}
