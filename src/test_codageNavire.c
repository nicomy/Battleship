#include <stdio.h>
#include <stdlib.h>
#include "codageNavires.h"

#define TAILLE 10


int main(int argc, char const *argv[])
{
	int i;
	liste_navire l;
	grille g;
	g = malloc(sizeof(char*)* TAILLE);
	for(i=0; i<TAILLE; i++){
		g[i] = malloc(sizeof(char)* TAILLE);
	}

	g[5][5] = 'N';
	g[6][5] = 'N';

	g[0][0] = 'N';
	g[0][1] = 'N';
	g[0][2] = 'N';

	printGrille(g, TAILLE);

	l = cree_liste_navires(g, TAILLE);

	return 0;
}