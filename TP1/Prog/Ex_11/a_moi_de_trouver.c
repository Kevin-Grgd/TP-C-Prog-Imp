/******************
 * Kévin GOURGAUD *
 *****************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*******
 * JEU *
 *******/

void jeu() {  
  int rep_u;                /* REPonse_User*/
  int rep_c = rand() %101;  /* REPonse_Computer*/
  int etape = 1;
  int borne_debut = 0;      /*Début intervalle recherche nombre*/
  int borne_fin = 100;      /*Fin intervalle recherche nombre*/


  printf("\nPensez à un nombre entier entre 0 et 100 que je vais devoir deviner. \nPrêt ? \nC'est parti ! \n\n\n");

  printf("Si le nombre auquel vous pensez est : \n   - Inférieur : Tapez 1 \n   - Supérieur : Tapez 2 \n   - C'est le bon : Tapez 0 \nVotre nombre est %d ? \n",rep_c);
  if (scanf("%d", &rep_u) < 1) {
    printf("Erreur : Vous avez entré une valeur incorrecte. \n");
    exit(EXIT_FAILURE);
  }

  
  while (rep_u > 0) {    /*Tant que le nombre n'est pas le bon*/
    etape++;


    
    if (rep_u == 1) {    /*Si le nombre de l'utilisateur est inférieur*/
      borne_fin = rep_c;
      while ((rep_c <= borne_debut) || (rep_c >= borne_fin)) {    /*Tant que le nombre n'est pas dans le bon intervalle*/
	rep_c = rand() %101;
      }
    }


    
    else if (rep_u == 2) {    /*Si le nombre de l'utilisateur est supérieur*/
      borne_debut = rep_c;
      while ((rep_c <= borne_debut) || (rep_c >= borne_fin)) {    /*Tant que le nombre n'est pas dans le bon intervalle*/
	rep_c = rand() %101;
      }
    }
    
    printf("\nNouvelle proposition : %d. \n(Inférieur : 1 / Supérieur : 2 / Juste : 0) \n",rep_c);
    if(scanf("%d", &rep_u) < 1) {
      printf("Erreur : Vous avez entré une valeur incorrecte. \n");
      exit(EXIT_FAILURE);
    }
  }
  printf("J'ai trouvé le nombre %d en %d étapes ! \n\n",rep_c,etape);
}



/***********************
 * FONCTION PRINCIPALE *
 ***********************/

int main() {
  int rej;
  srand(time(NULL));
  jeu();
  printf("Voulez-vous rejouez ? (Oui : 1 / Non 0) \n");
  if (scanf("%d", &rej) <1) {
    printf("Erreur : vous avez entré une valeur incorrecte. \n");
    exit(EXIT_FAILURE);
  }

  while (rej == 1) {
    jeu();
    printf("Voulez-vous encore jouer ? (Oui : 1 / Non : 0) \n");
    if (scanf("%d" ,&rej) < 1) {
      printf("Erreur : Vous avez entré une valeur incorrecte. \n");
      exit(EXIT_FAILURE);
    }
  }
  if (rej == 0) {
      printf("Merci d'avoir joué, à bientôt ! \n");
      exit(EXIT_SUCCESS);
  }
  exit(EXIT_SUCCESS);
}
