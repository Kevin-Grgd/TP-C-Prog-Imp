#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*|--------------------|
| Fonction du jeu      |
|----------------------|*/


void jeu() {
  int n, prop,etape;
  srand(time(NULL));

  n = rand() % 100;
  etape = 1;

  printf("La machine a choisi un nombre mystère entre 0 et 100. À vous de le trouver. \n");
  printf("Proposez un nombre : ");
  if (scanf("%d", &prop) < 0) {
    printf("Erreur : Vous n'avez pas entrez de valeur correct. \n");
    exit(EXIT_FAILURE);
      }

  while (prop != n) {
    if (prop < n) {
      printf("\nC'est faux, le nombre mystère est supérieur à %d. \n", prop);
      etape++;
      printf("Proposez un nouveau nombre : ");
      if (scanf("%d", &prop) < 0) {
	printf("Erreur : Vous n'avez pas entrez de valeur correct. \n");
	exit(EXIT_FAILURE);
      }
    } else {
      printf("\nC'est faux, le nombre mystère est inférieur à %d. \n", prop);
      etape++;
      printf("Proposez un nouveau nombre : ");
      if (scanf("%d", &prop) < 0) {
	printf("Erreur : Vous n'avez pas entrez de valeur correct. \n");
	exit(EXIT_FAILURE);
      }
    }
  }

  printf("\nC'est juste, vous avez trouvé %d en %d étapes. \n",n,etape);
}


/*|------------------------|
| Fonction principale      |
|--------------------------|*/


int main() {
  int rej;
  jeu();
  printf("Voulez-vous rejouez ? (Oui : 1 / Non : 0) \n");
  if (scanf("%d", &rej) != 1) {
    printf("Erreur : Vous n'avez pas entrez de valeur correct. \n");
    exit(EXIT_FAILURE);
  }
  while (rej == 1) {
    jeu();
    printf("Voulez-vous encore jouer ? (Oui : 1 / Non : 0) \n");
    if (scanf("%d", &rej) != 1) {
      printf("Erreur : Vous n'avez pas entrez de valeur correct. \n");
      exit(EXIT_FAILURE);
    }
  }
  if (rej == 0) {
    printf("Merci d'avoir joué, à bientôt ! \n");
    exit(0);
  }
  exit(0);
}
