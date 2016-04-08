#include "jeu.h"
//#include <affichage.h>
//#include <codageNavires.h>


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
	pbateau l ; 
	l = creatList() ;
	l = addbateau(l,"torpileurs",4,2 );
	l = addbateau(l,"contre-torpilleurs",3,3);
	l = addbateau(l,"croiseurs",2,4);
	l = addbateau(l,"porte-avion",1,6);
	return l ; 
}

int lbvide(pbateau l ){
	return (l == NULL) ;
}

//renvoit 0 s'il n'y plus de bateau à enlever, 1 sinon. 
pbateau enlever(pbateau l){
	pbateau tmp = l ;
	int nbr ;

	while(tmp != NULL && (tmp->nombre == 0)){
		tmp = tmp->nextbateau ; 
		printf("%d\n", tmp->nombre);
	}

	if(tmp != NULL){
		nbr = tmp->nombre ;
		tmp -> nombre = --nbr ; 
	}
	if(nbr== 0 ) {
		tmp= tmp->nextbateau ;
	}

	return tmp ;
}

// j = ligne et i = colonne. 
// /!\ gc[j][i] n'est pas encore joué !
// void joue(grille g, grille gc, int n, listebateau l, int i , int j ){

// 	if (g[j][i] == 'B')
// 	{
// 		gc[j][i] == 'X' ;
// 		printf("Rate\n");
// 	}
// }