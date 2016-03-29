/**#include <stdio.h>
#include <string.h>
#include <stdlib.h> **/
#include "affichage.h"

/**role de la fct joue : si 'B' en (i,j) -> raté 
sinon  on a toucher en (i,j)
-> appel de un_navire_coulé pour savoir si on a coulé

**/


typedef char** grille ; 

grille init_grille( int N, char c ){
	int i, j ; 
	grille g = malloc(N*sizeof(char*)) ;
	
	for (i=0;i<N; i++){
		g[i]= malloc(N);
	}

	for(i=0; i< N ; i ++ ){
		for(j=0; j< N ; j++){
			g[i][j] = c;
		}
	}  
	return g;
}


void afficher_jeu(grille g , int N ) {
	int i, j ; 

	printf("\t");

	for(i=0; i< N ; i ++ ){

		printf("%c ", i + 'A' );

	}
	printf("\n\n");
	for(i=0; i< N ; i ++ ){
		printf("%d \t",i);
		
		for(j=0; j< N ; j++){
			if(g[i][j] == 'B')  printf("  " );
			else printf("%c ",  g[i][j] );
		}

		printf("\n");
	}
	printf("\n");
}

void affiche_etat_coules(grille g, int N ){
	int i, j ; 

	printf("\t");

	for(i=0; i< N ; i ++ ){

		printf("%c ", i + 'A' );

	}
	printf("\n\n");
	for(i=0; i< N ; i ++ ){
		printf("%d \t",i);
		
		for(j=0; j< N ; j++){
			printf("%c ",g[i][j] );
		}

		printf("\n");
	}
	printf("\n");}

