#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "affichage.h"
#include "codageNavires.h"

//fonction qui permet de convertir un nombre qui est dans une cchaine de caractère en int lissible.
int char_to_int(const char* t, int debut){
	int res= 0 , i = debut; 
	while(t[i]!='\0'){
		res = res*10 + t[i] -'0';
		i++;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	liste_navire l ;
	int N   ;
	int compteur = 0,i ,j ;
	char coup[10] ; 
	grille gc , g  ;

	// par defaut s'il n'y pas de deuxième argument on initie N à 10 
	if(argc<2){
		N = 10 ; 
	}
	else{
		N = char_to_int(argv[1],0);
	}
	gc = init_grille ( N , ' ' ) ;
	g = init_grille(N, 'B') ;

	printf("Le joueur 1 doit placer les bateaux \n");
	//usr_remplir_grille(g, N );
	remplir_gille(g,N) ;
	l = cree_liste_navires(g, N);

	printf("au joueur 2 d'essayer de couler les navires.\n");
	while(!jeu_fini(l)){
		printf("\nVoici la grille\n");
		affiche_etat_coules(gc, N );
		printf("veuillez entrer les coordonées du tir (ex: \"E5\")\n");
		scanf("%s",coup);
		if(strlen(coup)<2){

			printf("coordonnée trop court il faut rentrer les 2 paramètre colonne et ligne\n");
		}
		else{
			j = coup[0] - 'A' ;
			i = char_to_int(coup, 1);

			if (i<0 || j<0 || i>(N-1) || j > N-1)
			{
				printf("\n\nVos coordonnées sortent du tableau ou son invalide \n\n");
			}
			else{

				joue(g,gc,N,l,i,j); 
				printf("\n");
				compteur++ ;
			}
		}
	}

	printf("vous avez fini le jeu en %d tirs \nLa disposition des bateaux est :\n", compteur );
	afficher_jeu(g,N);

	//libération des grilles
	free_grille(g,N);
	free_grille(gc,N);

	return 0;
}