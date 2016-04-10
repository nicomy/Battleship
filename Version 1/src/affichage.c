/**#include <stdio.h>
#include <string.h>
#include <stdlib.h> **/
#include "affichage.h"

/**role de la fct joue : si 'B' en (i,j) -> raté 
sinon  on a toucher en (i,j)
-> appel de un_navire_coulé pour savoir si on a coulé

**/


typedef char** grille ; 

//permet d'initialiser a grille en y plaçant le caractère c.
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

//libère la mémoire allouée pour une grille.
void free_grille(grille g, int N){
	int i ; 

	for(i=0;i<N;i++){
		free(g[i]);
	}
	free(g);
}




//revoit la taille du bateau entré par l'utilisateur.
int taille( char debut[], char fin[]){
	int i,j, compteur = 0; 

	for (i = debut[0]; i <= fin[0]; ++i)
	{
		for (j = debut[1]; j <= fin[1]; ++j)
		{
			compteur++;
		}
	}

	return (compteur) ;
}

//permet de convertir le buf en cordonné utilisable 
void recup_donnee(char* buf, char* debut, char* fin ){
	int i=1, lg = strlen(buf);
	int tmp; 


	debut[0] = buf[0] -'A' ;
	debut[1] = 0;

	//permet de convertir le premier nombre de char en int
	while(i<lg && buf[i] != '-'){
		debut[1] = debut[1]*10 + buf[i] -'0' ;
		i++ ;
	}
	fin[0] = buf[++i] -'A';
	i++ ;
	fin[1] = 0 ;

	//permet de convertir le deuxième nombre de char en int
	while(buf[i] != '\0' ){
		fin[1] = fin[1]*10 + buf[i++] - '0' ;
	}

	//remet dans l'ordre si besoin le debut et la fin du bateau.
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

}

//fonction qui va tester si les coordonnées sont valide et renvoi 1 si le bateau peut être placer 0 sinon.
int mettable(grille g, int n, char debut[], char fin[], pbateau l ){
	int i, j ,tmp; 
	int res = 1 ;

	//test si les coordonées sortent du tableaux (peut aussi être du à une entrée incorrecte)
	if (!(debut[0]== fin[0] || debut[1] == fin[1]))
	{
		printf("votre bateau doit être en ligne!\n");
		res = 0 ; 
	}
	else if (debut[0]<0 || debut[1]<0 || fin[0]>(n-1) || fin[1] > n-1)
	{
		res = 0 ;
		printf("\n\nVos coordonnées sortent du tableau ou son invalide pensez à bien mettre '-' pour séparer le début et la fin du bateau\n\n");
	}
 	else{
 		// teste si la taille rentré est idetique avec celle attendu pour ce type de bateau. 
 		tmp = taille(debut,fin) ;
 		if( tmp != l->nb_cases){
			printf("Vous essayez de mettre un bateau de %d cases alors que le %s en demande %d\n",tmp,l->nom, l->nb_cases);
		}
		else{
			//regarde si à coté de chaque case un bateau n'est pas déjà présent. 
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
			//dit au joueur qu'un bateau est présent
			if(!res){
				printf("\n\nVous ne pouvez pas palcer votre bateau directement à coté d'un autre.\n");
			}
		}
	}
	return res; 
}

//remplit la grille depuis un ficher.
void remplir_gille (grille g, int n ){
	char buf[10] = "" ;
	char debut[2] = "" ;
	char fin[2] = "" ;
	char tmp ; 
	int i , j  ; 
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
	   		


	   		//if(mettable(g,n,debut,fin,l)){
		   		for (i= debut[0]; i<= fin[0];i++ ){
		   			for(j= debut[1];j<=fin[1];j++){
		   				g[j][i] = 'N' ;
		   			}
		   		}
		   	//}
	   	}
   		fclose(fichier);
   		afficher_jeu(g,n);
    }
}


//identique à remplir grille mais pour l'utilisateur. 
void usr_remplir_grille(grille g, int n ){
	char buf[10] = "" ;
	char debut[2] = "" ;
	char fin[2] = "" ; 
	int i , j ; 
	pbateau l = initbat();	
	pbateau meml = l ; // permet de garder en mémoire le début de la liste pour pouvoir la liberer plus tard.

	printf("boujour\n");

	while(!lbvide(l)){
		printf("voici la grille : \n");
		afficher_jeu(g, n);
		printf("Veuillez placer le bateau %s, qui fait %d cases \n",l->nom, l->nb_cases );
		printf("Rentrez les coordonées de debut et de fin du bateau (ex : \"J0-J5\")\n");
		scanf("%s",buf);

		if (strlen(buf) < 5){
			printf("il manque des données dans ce que vous avez rentrez (ex \"A0-A5\" ) p\n");
		}
		else{

	   		recup_donnee(buf,debut,fin) ; //met les coordonnée du début du navire dans début et de fin dasn fin
			
			if (mettable(g,n,debut,fin,l))
	   		{
   				//remplir a grille coorespondant à l'emplacement désiré qui est validé
	   			for (i= debut[0]; i<= fin[0];i++ ){
		   			for(j= debut[1];j<=fin[1];j++){
		   				g[j][i] = 'N' ;
		   			}
			   	}
			   	//décrémente le nombre bateau restant.
			   	if(l!=NULL){
			   		l=enlever(l);
			   	}

	   		}
	   	}
	}
	free_l(meml);

}