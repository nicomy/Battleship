#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char** grille ; 


void afficher_jeu(grille g , int N ) ;
void affiche_etat_coules(grille g, int N );
grille init_grille ( int N , char c ) ;
void remplir_gille (grille g, int n );