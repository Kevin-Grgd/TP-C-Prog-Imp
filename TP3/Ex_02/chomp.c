#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>

#define TAILLE_MAX 50



/*Définition des types*/
/*Type : Tablette*/
typedef struct {
  int n;
  int m;
  int t[TAILLE_MAX][TAILLE_MAX];
} tablette;

/*Type : Joueur*/
typedef enum { j1, j2 } joueur;

/*Type : Configuration*/
typedef struct {
  tablette table;
  joueur joueurN;
} configuration;

/*Type : Coup*/
typedef struct {
  int x;
  int y;
} coup;



/*Définition des fonctions*/
/*Créer tablette*/
tablette creer_tablette(int n, int m) {
  int i;
  int j;
  tablette tab;
  tab.n = n;
  tab.m = m;

  for (i = 0; i < n; i++) {
    for (j = 0; i < m; j++) {
      tab.t[i][j] = 1;
    }
  }
  return tab;
}

/*Manger carré*/
void manger(tablette *t, int x, int y) {
  int i,j;

  for (i = x; i < t->n; i++) {
    for (j = y; j < t->m; j++) {
      t->t[i][j] = 0;
    }
  }
}

/*Coup légal*/
int est_legal (configuration *config, coup *cp) {
  if (config->table.t[cp->x][cp->y] == 1) {
    return 1;
  }
  else {
    return 0;
  }
}

/*Partie finie*/
int est_finie (configuration *config, joueur *gagnant) {
  if (config -> table.t[0][0] == 0) {
    if (config -> joueurN == j1) {
      *gagnant = j2;
    } else {
      *gagnant = j1;
    }
    return 1;
  }
  else {
    return 0;
  }
}

/*Jouer coup*/
void jouer_coup (configuration *config, coup *cp) {
  manger(&config->table, cp->x, cp->y);
  if (config->joueurN == j1) {
    config->joueurN = j2;
  }
  else {
    config->joueurN = j1;
  }
}





/*Assemblage du jeu*/
/*Affichage de la configuraiton*/
void afficher_configuration(configuration *config) {
  int i,j,x,y;

  for(i = 0; i < config->table.n; i++) {
    for (j = 0; j < config->table.m; j++) {
      x = i*50;
      y = j*50;
      if ((config -> table.t[i][j] == 1 && (((i%2==0) && (j%2==0)) || ((i%2!=0) && (j%2!=0))))) {
	MLV_draw_filled_rectangle(x,y,x+50,y+50,MLV_rgba(167, 85, 2,255));
      }
      else if (config -> table.t[i][j] == 1) {
	MLV_draw_filled_rectangle(x,y,x+50,y+50,MLV_rgba(253, 233, 224,255));
	}
      else {
	MLV_draw_filled_rectangle(x,y,x+50,y+50,MLV_COLOR_BLACK);
      }
    }
  }
  MLV_actualise_window();
}

/*Lire coup*/
coup lire_coup (configuration *config) {
  int x,y;
  coup clique;

  do {
    MLV_wait_mouse(&x,&y);
    clique.x = x/50;
    clique.y = y/50;
  } while (est_legal(config,&clique) == 1);
  return clique;
}


void usage(char *s) {
  printf("Usage : %s <largeur> <longueur>, n et m deux entiers positifs strictement supérieur à 0 \n",s);
  exit(EXIT_FAILURE);
}





/*Programme principal*/
int main(int argc, char *argv[]) {
  int n,m,longueur,largeur;
  configuration config;
  coup cp;
  tablette table_jeu;


  if (argc != 3) {
    usage(argv[0]);
  }


  n = atoi(argv[1]);
  m = atoi(argv[2]);
  longueur = m*50;
  largeur = n*50;
  
  MLV_create_window("Chomp","Chomp",largeur,longueur);
    
  table_jeu = creer_tablette(n,m);
  config.table = table_jeu;
  config.joueurN = j1;
  afficher_configuration(&config);

  while (est_finie(&config,&config.joueurN) != 1) {
    cp = lire_coup(&config);
    jouer_coup(&config,&cp);
    afficher_configuration(&config);
  }


  if (config.joueurN == j1) {
    MLV_draw_adapted_text_box((largeur/2),(longueur/2), "Gagnant : \nJoueur 1",5,MLV_COLOR_RED,MLV_COLOR_GREEN,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  }
  else {
    MLV_draw_adapted_text_box((largeur/2),(longueur/2), "Gagnant : \nJoueur 2",5,MLV_COLOR_RED,MLV_COLOR_GREEN,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
  }
  MLV_actualise_window();
  MLV_wait_seconds(10);
  MLV_free_window();
  exit(EXIT_SUCCESS);
}
