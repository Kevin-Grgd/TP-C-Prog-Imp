#include <stdio.h>
#include <stdlib.h>

#define TAILLe_MAX 200

typedef struct {
  int numero;
  char nom[50];
  char prenom[50];
} Personne;


int stocker (personne tab[]) {
  int i = 0;
  FILE *fichier = NULL;
  fichier = fopen("fichier_tri.txt","r");

  if (fichier == NULL) {
    printf("Erreur, fichier inconnu.\n");
    exit(EXIT_FAILURE);
  }

  while (fscanf(fichier,"%d %s %s", &tab[i].numero, &tab[i].nom, &tab[i].prenom) == 3) {
    i++;
  }
  fclose(fichier);
  return i;
}

void afficher (personne tab[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d %s %s", &numero, &nom, &prenom);
    printf("\n");
  }
}
