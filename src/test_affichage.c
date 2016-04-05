#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "affichage.h"

int main(){
	int N = 10 ;
	grille g1, g2 ;
	//g1 = init_grille(N, 'B');
	g2= init_grille(N,'B') ;
	/*g1[4][4]='N';
	g1[4][5]='N';
	g1[4][6]='N';

	g1[2][7]='N';
	g1[3][7]='N';
	afficher_jeu(g1,N);
	affiche_etat_coules(g1,N);*/

	remplir_gille (g2, N );
	afficher_jeu(g2,N);


	/**faire une fonctino popur liberer la mémoire tq 
	for (i = 0; i < n; i++)
        free(m[i]);

    désallocation mémoire du tableau de sous-tableaux :   
    free(m);*/


	return 0;

}