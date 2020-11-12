#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a,b,tmp;
  srand(time(NULL));
  a = rand() % 50;
  b = rand() % 50;
  printf("a : %d, b : %d\n",a,b);
  tmp = a;
  a = b;
  b = tmp;
  printf("a : %d, b : %d\n",a,b);
  exit(EXIT_SUCCESS);
}
