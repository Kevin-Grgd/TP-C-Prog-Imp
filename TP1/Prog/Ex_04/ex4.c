#include <stdio.h>
#include <stdlib.h>

int main() {
  int a,b,q,r;
  
  /* ----- Entrée et lecture de a et b ----- */
  printf("Entrez la valeur de a : ");
  if (scanf("%d", &a) < 1) {
    printf("\n");
    printf("Entrez UNE valeur !\n");
    exit(EXIT_FAILURE);
  }
  printf("Entrez la valeur de b : ");
  if (scanf("%d", &b) != 1) {
    printf("\n");
    printf("Entrez UNE valeur !\n");
    exit(EXIT_FAILURE);
    }
  
  /* ----- Affichage de a et b ----- */
  printf("\nValeur de a : %d\nValeur de b : %d \n\n",a,b);

  /* ----- Calcul de la somme et du produit ----- */
  printf("Résultat de la somme a + b :\n%d + %d = %d\n\n",a,b,a+b);
  printf("Résultat du produit a * b :\n%d * %d = %d\n\n",a,b,a*b);

  /* ----- Calcul de la division euclidienne ----- */
  if (b > a) {
    printf("a est plus petit que b, la division est impossible !\n");
    exit(EXIT_FAILURE);
  } else {
    q = a/b;
    r = a % b;
    printf("Résultat de la division a / b :\nQuotient : %d \n",q);
    if (r != 0) {
      printf("Reste : %d\n",r);
    }
    exit(EXIT_SUCCESS);
  }
}
