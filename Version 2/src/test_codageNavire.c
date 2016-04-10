#include <stdio.h>
#include <stdlib.h>
#include "codageNavires.h"

#define TAILLE 10


int main(int argc, char const *argv[])
{
	int i;
	liste_navire l;
	pMaillon current;
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

	//printGrille(g, TAILLE);

	l = cree_liste_navires(g, TAILLE);

	current = l.first;
	if(current == NULL){printf("erreur de liste");}
	while(current != NULL){
		current->coule = 1;
		current = current->nextMaillon;
	}

	//printGrille(g, TAILLE);
	//printf("%d\n", jeu_fini(l));


/**************************************************************************/
	grille gc;
	gc = malloc(sizeof(char*)* TAILLE);
	for(i=0; i<TAILLE; i++){
		gc[i] = malloc(sizeof(char)* TAILLE);
	}
	gc[5][5] = 'X';
	gc[6][5] = 'X';

	//gc[0][0] = 'N';
	//gc[0][1] = 'N';
	gc[0][2] = 'T';

	//printf("%d\n", navire_coule(l.first, 0, 1, gc));
	printGrille(gc, TAILLE);
	joue(g, gc, TAILLE, l, 0, 0);
	printGrille(gc, TAILLE);
	joue(g, gc, TAILLE, l, 4, 1);
	printGrille(gc, TAILLE);
	joue(g, gc, TAILLE, l, 0, 1);
	printGrille(gc, TAILLE);
	joue(g, gc, TAILLE, l, 5, 5);
	joue(g, gc, TAILLE, l, 6, 5);
	joue(g, gc, TAILLE, l, 4, 5);
	joue(g, gc, TAILLE, l, 7, 5);
	printGrille(gc, TAILLE);
	return 0;
}