#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "affichage.h"
#include "codageNavires.h"


int char_to_int(const char* t){
	int res= 0 , i =0; 
	while(t[i]!='\0'){
		res = res*10 + t[i] -'0';
		i++;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	int N = char_to_int(argv[1]);//argv[1][0] - '0' ;
	int compteur = 0,i ,j ;
	char coup[10] ; 
	grille gc = init_grille ( N , ' ' ) , g = init_grille(N, 'B') ;
	liste_navire l ;

	printf("Le joueur 1 doit placer les bateaux \n");
	//usr_remplir_grille(g, N );
	remplir_gille(g,N) ;
	l = cree_liste_navires(g, N);

	printf("au joueur 2 d'essayer de couler les navires.\n");
	while(!jeu_fini(l)){
		printf("Voici la grille\n");
		affiche_etat_coules(gc, N );
		printf("veuillez entrer les coordonées du tir (ex: \"E5\")\n");
		scanf("%s",coup);
		if(strlen(coup)<2){

			printf("coordonnée trop court il faut rentrer les 2 paramètre colonne et ligne\n");
		}
		else{
			j = coup[0] - 'A' ;
			i = coup[1] -'0' ;

			if (i<0 || j<0 || i>(N-1) || j > N-1)
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