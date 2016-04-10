#include "jeu.h"

//fonction qui ajoute un bateau dans la liste.
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

//crée une liste_bateu vide
pbateau creatList(){
	pbateau l = malloc(sizeof(listebateau));
	if(l == NULL){
		printf("erreur d'alocation\n");
		exit(0);
	}
	l = NULL ; 
	return l ;
}

//permet de remplir la liste avec tous les bateaux , leurs nombres et leurs taille.
pbateau initbat (){
	pbateau l ; 
	l = creatList() ;
	l = addbateau(l,"torpileurs",4,2 );
	l = addbateau(l,"contre-torpilleurs",3,3);
	l = addbateau(l,"croiseurs",2,4);
	l = addbateau(l,"porte-avion",1,6);
	return l ; 
}

//test si la liste est vide ou non 
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

//fonction pour liberer la liste à la fin. 
void free_l(pbateau l){
	pbateau tmp  ;

	while(l != NULL){
		tmp = l ;
		l = l->nextbateau ;
		free(tmp);
	}
}