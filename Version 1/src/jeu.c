//Antoine Blanc et Nicolas Homberg
#include "jeu.h"

/**fonction qui ajoute un bateau dans la liste
*param:	b: list de bateau ou on ajoute le bateau 
*		nom_bat: nom du bateau
*		nbr: nombre de ce bateau 
*		nbcase :: nombre de case de ce type de bateau
*return: la liste avec un type de bateau ajouté
*/
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
//return : un eliste de bateau vide
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
//return la liste complete des bateaux.
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

/**fonction qui enlève un bateau dans la liste
*param:	: list de bateau ou l'on veut enlever un 
*return: renvoi la liste avec un bateau en moins
*/
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