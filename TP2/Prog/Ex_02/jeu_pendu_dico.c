#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10


int enreg_secr (char mot_secret[]) {
  int lg;
  printf("Donner le mot secret : ");
  if (fgets (mot_secret, N, stdin) == NULL) {
    printf("Erreur \n");
    exit(EXIT_FAILURE);
  }
  lg = strlen (mot_secret);
  return (lg-1);
}


int enreg_secr_bis(char mot_secret[]) {
  FILE* fic_mots = NULL;
  int nbMots = 0;
  int numMot;
  int caract = 0;
  int lg;

  fic_mots = fopen("fic-mots-secrets.txt","r");
  if (fic_mots == NULL) {
    printf("Ouverture du dictionnaire de mot impossible.\n");
    exit(EXIT_FAILURE);
  }

  /*Comptage du nombre de mots*/
  while (caract != EOF) {
    caract = fgetc(fic_mots);
    if (caract == '\n') {
      nbMots++;
    }
  }

  /*Tirage d'un mot au hasard*/
  numMot = rand() % nbMots;
  rewind(fic_mots); /*retour au début du fichier*/
  do {
    caract = fgetc(fic_mots);
    if (caract == '\n')
      numMot--;
  } while (numMot > 0);
  if (fgets(mot_secret,100,fic_mots) == NULL) {
    printf("Erreur \n");
    exit(EXIT_FAILURE);
  }
  lg = strlen(mot_secret);
  mot_secret[lg-1] = '\0'; /*remplacement du saut de ligne par \0*/

  fclose(fic_mots);
  return (lg-1);
}


void aff_tab (char t[], int n) {
  int i;
  for (i=0; i<n ; i++) {
    printf("%c ", t[i]);
      }
  printf("\n");
}


void poser_lettre (char c, char mot_secret[], int lg, char tab[]) {
  if (strchr(mot_secret,c) != NULL) {
    int i;
    for (i = 0; i < lg; i++) {
      if (mot_secret[i] == c) {
	tab[i] = c;
      }
    }
    printf("\nMot secret : ");
    aff_tab(tab,lg);
  } else {
    printf("\nLettre absente !\n\n");
  }
}


void essai_mot (char mot_secret[]) {
  char mot_propose[N];
  while (getchar() != '\n');
  printf("Votre mot : ");
  if (fgets (mot_propose,N,stdin) == NULL) {
    printf("Erreur \n");
    exit(EXIT_FAILURE);
  }
  mot_propose[strlen(mot_propose)-1] = '\0';
  if (strcmp(mot_propose,mot_secret) == 0) {
    printf("Gagné !\n\n");
  } else {
    printf("Perdu !\nLe mot secret était %s.\n\n",mot_secret);
  }
  printf("APPUYEZ SUR LA TOUCHE ENTREE POUR RETOURNER AU MENU PRINCIPAL\n");
}


void essai_lettre (char mot_secret[], int lg, char tab[]) {
  char lettre;
  printf("Votre lettre : ");
  while (getchar() != '\n');
  lettre = getchar();
  poser_lettre (lettre,mot_secret,lg,tab);
}


void jeu() {
  char mot_secret[N];
  char tab[N];
  int lg;
  int i;
  int rep_user;
  int etape = 1;
  
  lg = enreg_secr_bis(mot_secret);
  printf("Le mot secret a %d lettres \n",lg);
  for (i=0; i < N; i++) {
    tab[i] = '_';
  }
  printf("Contenu du tableau : ");
  aff_tab(tab,lg);
  
  while (etape < 10) {
    printf("Que voulez-vous proposer ? Un mot : 1 / Une lettre : 2 \nVotre réponse : ");
    while (scanf("%d",&rep_user) < 1) {
      printf("Erreur saisie valeur.\n");
    }
    if (rep_user == 2) {
      essai_lettre(mot_secret,lg,tab);
      etape++;
    }
    else if (rep_user == 1) {
      etape = 10;
    }
  }
  if (rep_user != 1) {
    printf("Dernière chance de trouver le bon mot sinon c'est perdu !\n");
    printf("ATTENTION !!!\nPROPOSEZ UN MOT !!!\n");
  }
  essai_mot(mot_secret);
}


int menu() {
  char choix;
  printf("__________________________\n");
  printf("|     MENU PRINCIPAL     |\n");
  printf("|                        |\n");
  printf("| (J) : Jouer au pendu   |\n");
  printf("| (A) : Ajouter un mot   |\n");
  printf("| (Q) : Quitter          |\n");
  printf("|                        |\n");
  printf("|________________________|\n");
  printf("\nVotre choix : ");
  if(scanf("%c",&choix) != 1) {
    printf("Erreur de saisie.\n");
    exit(EXIT_FAILURE);
  }
  printf("\n");
  return choix;
}
	 

void ajout_mot() {
  FILE* fic_mots = NULL;
  char mot_ajoute[N];

  fic_mots = fopen("fic-mots-secrets.txt","a");
  if (fic_mots == NULL) {
    printf("Ouverture du dictionnaire de mot impossible.\n");
  }
  else {
    while (getchar() != '\n');
    printf("Entrez le mot que vous voulez ajouter au dictionnaire : ");
    if (fgets (mot_ajoute,N,stdin) == NULL) {
      printf("Erreur \n");
      exit(EXIT_FAILURE);
    }
    if (strlen(mot_ajoute) > 10) {
	printf("Erreur : Le mot que vous voulez ajouter contient plus de 10 lettres !\n");
    }
    else {
      mot_ajoute[strlen(mot_ajoute)-1] = '\0'; /*remplace le dernier caractere \n par \0*/
    }
    fprintf(fic_mots,"%s",mot_ajoute);
    printf("Merci d'avoir ajouté le mot %s à la liste !\n",mot_ajoute);
    printf("\nAPPUYEZ SUR LA TOUCHE ENTREE POUR REVENIR AU MENU PRINCIPAL\n");

    fclose(fic_mots);
  }
}
      
    

int main() {
  char choix;
  srand(time(NULL));
  
  do {
    choix = menu();
    if (choix == 'J') {
      jeu();
    }
    else if (choix == 'A') {
      ajout_mot();
    }
    else if ((choix != 'A') || (choix != 'J') || (choix != 'Q')){
      printf("Choix inconnu.\n");
    }
    while(getchar() != '\n');
  } while (choix != 'Q');
  printf("Merci d'avoir joué au pendu, bonne journée !\n");
  exit(EXIT_SUCCESS);
  
}
