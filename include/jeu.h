#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "affichage.h"

typedef struct _bateau* pbateau;

typedef struct _bateau
{
	char* nom;
	int nombre;
	int nb_cases;
	pbateau nextbateau;
}listebateau;

pbateau addbateau(pbateau b,char* nom_bat,int nbr,int nbcase);
pbateau creatList();
pbateau initbat ();
int lbvide(pbateau l );
pbateau enlever(pbateau l) ;



//void joue(grille g, grille gc, int n, liste_navires l, int i , int j );