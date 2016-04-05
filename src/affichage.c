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
	printf("\n");

}


int mettable(grille g, int n, char debut[], char fin[]){
	int i, j ; 
	int res = 1 ;

	if (debut[0]<0 || debut[1]<0 || fin[0]>(n-1) || fin[1] > n-1)
	{
		res = 0 ;
	}
	else{
		for (i= debut[0]; i<= fin[0]; i++ ){
			for(j= debut[1]; j<=fin[1]; j++){
				
				if( (j+1 <= (n-1)) && g[j+1][i] == 'N' ){
					res = 0 ;
				}
				else if ((j-1 >= 0) && g[j-1][i] == 'N' ){
					res = 0 ; 
				}
				else if ( (i+1 <= (n-1)) && g[j][i+1] == 'N'  ){
					res = 0 ; 
				}
				else if( (i-1 >= 0) && g[j][i-1] == 'N'  ){
					res = 0 ;
					//break ; ? 
				}
   			}
		}
	}
	return res; 
}

void remplir_gille (grille g, int n ){
	char buf[10] = "" ;
	char debut[2] = "" ;
	char fin[2] = "" ;
	char tmp ; 
	int i , j ; 
	FILE* fichier = NULL;

    fichier = fopen("remplissage.txt", "r");
    
   	if (fichier != NULL){
   		
   		while(fgets(buf,10, fichier) !=  NULL){
	   		debut[0] = buf[0] - 'A' ;
	   		debut[1] = buf[1] - '0' ; 
	   		fin[0] = buf[3] - 'A' ;
	   		fin[1] = buf[4] - '0' ; 

	   		if(debut[0]>fin[0]){
	   			tmp = debut[0];
	   			debut[0] = fin[0];
	   			fin[0] = tmp ; 
	   		}

	   		if(debut[1]>fin[1]){
	   			tmp = debut[1];
	   			debut[1] = fin[1];
	   			fin[1] = tmp ;
	   		}

	   		if(mettable(g,n,debut,fin)){
		   		for (i= debut[0]; i<= fin[0];i++ ){
		   			for(j= debut[1];j<=fin[1];j++){
		   				g[j][i] = 'N' ;
		   			}
		   		}
		   	}
	   	}
   		fclose(fichier);
    }
}