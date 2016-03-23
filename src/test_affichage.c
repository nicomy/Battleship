#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "affichage.h"

int main(){
	int N = 12 ;
	grille g1 ;
	g1 = init_grille(N, 'B');
	g1[4][4]='N';
	g1[4][5]='N';
	g1[4][6]='N';

	g1[2][7]='N';
	g1[3][7]='N';
	afficher_jeu(g1,N);
	affiche_etat_coules(g1,N);

	return 0;

}