#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _bateau* pbateau;

typedef struct _bateau
{
	char* nom;
	int nombre;
	int nb_cases;
	pbateau nextbateau;
}listebateau;


void joue(grille g, grille gc, int n, liste_navires l, int i , int j );