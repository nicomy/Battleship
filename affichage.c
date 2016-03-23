#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef char** grille ; 

/**void init_grille( grille g ){
*
} **/

void afficher_jeu(grille g , N ) {
	int i, j ; 


	printf("\t")
	for(i=0, i<= N , i ++ ){
	
	if (i<9) printf("%d ",i); //pour gerer le l'affichage pour les nombres à deux chiffres.

	else printf("%d",i) ;

	}

	for(i=0, i<= N , i ++ ){
		printf("i\t",i);
		for(j=0, i<= N , j++){
			
		}

	}
}