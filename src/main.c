#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "jeu.h"
#include "affichage.h"
#include "codageNarvires.h"


int main(int argc, char const *argv[])
{
	N = argv[1] - '0' ;
	int compteur = 0,i ,j ;
	char coup[10] ; 
	grille gc = init_grille ( N , ' ' ) , g = init_grille(N, 'B') ;
	liste_navire l ;

	printf("Le joueur 1 doit placer les bateaux \n");
	usr_remplir_grille(g, N );
	l = cree_liste_navires(g, N);

	printf("au joueur 2 d'essayer de couler les navires.\n");
	while(jeu_fini(l)){
		printf("Voici la grille\n");
		affiche_etat_coules(gc, N );
		printf("veuillez entrer les coordonées du tir (ex: \"E5\")\n");
		scanf("%s",coup);
		if(strlen(coup)<2){

			printf("coordonnée trop court il faut rentrer les 2 paramètre colonne et ligne\n");
		}
		else{
			i = coup[0] - 'A' ;
			j= coup[1] -'0' ;

			if (i<0 || j<0 || i>(n-1) || j > n-1)
			{
				printf("\n\nVos coordonnées sortent du tableau ou son invalide \n\n");
			}
			else{

				joue(g,gc,N,l,i,j); 
				compteur++ ;
			}
		}
	}

	printf("vous avez fini le jeu en %d tirs \nLa disposition des bateaux est :\n", compteur );
	afficher_jeu(g,N);

	return 0;
}