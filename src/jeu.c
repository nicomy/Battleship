#include <jeu.h>
#include <affichage.h>
#include <codageNavires.h>


pbateau addbateau(pbateau b,char* nom_bat,int nbr,int nbcase){
	pbateau nbateau = malloc(sizeof(listebateau));
	
	if(nbateau == NULL){
		printf("erreur d'alocation\n");
		exit(0);
	}

	nbateau-> nom = nom_bat ;
	nbateau -> nombre = nbr ;
	nbateau-> nb_cases = nbcase ;
	nbateau->nextbateau = b; 

	return nbateau;
}

pbateau creatList(){
	pbateau l = malloc(sizeof(listebateau));
	if(l == NULL){
		printf("erreur d'alocation\n");
		exit(0);
	}
	l = NULL ; 
	return l ;
}

pbateau initbat (){
	l = creatList() ;
	l = addbateau(l,"torpileurs",4,2 );
	l= addbateau(l,"contre-torpilleurs",3,3);
	l= addbateau(l,"croiseurs",2,4);
	l=addbateau(l,"porte-avion",1,6);
	return l ; 
}



// j = ligne et i = colonne. 
// /!\ gc[j][i] n'est pas encore joué !
void joue(grille g, grille gc, int n, liste_navires l, int i , int j ){

	if (g[j][i] == 'B')
	{
		gc[j][i] == 'X' ;
		printf("Rate\n");
	}
}