#include <stdio.h>
#include <stdlib.h>
#define N 25 /*Taille max du tableau */

#include <time.h>


void remplir_tab_alea(int t[], int n) {
  int i;
  int nb_alea;
  for (i = 0; i < n; i++) {
    nb_alea = rand() %(16-(-15)) -15;
    t[i] = nb_alea;
  }
}



void afficher_tab(int t[], int n) {
  int i;
  for (i = 0; i < n ; i++) {
    printf("%d | ", t[i]);
  }
  printf("\n");
}



void min_max_tab(int t[], int n) {
  int i;
  int min = t[0];
  int max = t[0];
  for (i = 0; i < n; i++) {
    if (min > t[i]) {
      min = t[i];
    }
    if (max < t[i]) {
      max = t[i];
    }
  }
  printf("Minimum : %d. \nMaximum : %d. \n",min,max);
}



double moyenne(int t[], int n) {
  int i;
  int somme = 0;
  for (i = 0; i < n; i++) {
    somme += t[i];
  }
  printf("Moyenne : %f \n", (float)somme/n);
  return (float)somme/n;
}



void renverser_tab(int t1[], int t2[], int n) {
  int i = 0;
  int j;

  for (j = n-1 ; j >= 0; j--) {
    t2[j] = t1[i];
    i++;
  }
}



void modulo_tab(int t2[], int t3[],  int n) {
  int i;
  for (i = 0; i < n; i++) {
    t3[i] = t2[i] % 4;
  }
}



void nb_occurence(int t[], int n, int x) {
  int i;
  int nb_occ = 0;
  for (i = 0; i < n; i++) {
    if (t[i] == x) {
      nb_occ++;
    }
  }
  printf("Nombre d'occurences de %d : %d \n",x,nb_occ);
}



void nb_pair_tab(int t1[], int t_pair[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    if (t1[i] % 2 == 0) {
      t_pair[i] = t1[i];
    }
  }
}



int main() {
  int t1[N];
  int t2[N];
  int t3[N];
  int t_pair[N];
  srand(time(NULL));
  remplir_tab_alea(t1,N);
  printf("Tableau 1 :\n");
  afficher_tab(t1,N);
  min_max_tab(t1,N);
  moyenne(t1,N);
  renverser_tab(t1,t2,N);
  printf("\nTableau 2 (renversement de T1) :\n");
  afficher_tab(t2,N);
  modulo_tab(t2,t3,N);
  printf("\nTableau 3 (modulo 4 de T2) :\n");
  afficher_tab(t3,N);
  nb_occurence(t3,N,0);
  nb_pair_tab(t3,t_pair,N);
  printf("\nTableau 4 (nombres pairs de T3) :\n");
  afficher_tab(t_pair,N);
  exit(EXIT_SUCCESS);
}
