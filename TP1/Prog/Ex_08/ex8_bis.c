#include <stdio.h>
#include <stdlib.h>

int main() {
  int i,table;

  for (table=2; table <=9; table++){
    printf("Table de %d : \n",table);
    for (i=1; i<=10; i++) {
      printf("%d x %d = %d \n",i,table, i*table);
    }
    printf("\n");
  }
  exit(EXIT_SUCCESS);
}
