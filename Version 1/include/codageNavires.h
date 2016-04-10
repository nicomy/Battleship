//Antoine Blanc et Nicolas Homberg
#include <stdio.h>
#include <stdlib.h>
#include "integer.h"



typedef struct $list
{
	pMaillon first;
	pMaillon last;
}liste_navire, *pListe_navire;



typedef char** grille;

liste_navire addNavire(liste_navire list, pMaillon n);

pMaillon creatNavire(int i_first, int j_first, int i_end, int j_end);

liste_navire liste_vide();

pMaillon find_navire(grille g, int n, int i, int j);

liste_navire cree_liste_navires(grille g, int n);

void printGrille(grille g, int taille);

int jeu_fini(liste_navire l);

int navire_coule(maillon* m, int ic, int jc, grille gc);

void joue(grille g, grille gc, int n, liste_navire l, int i, int j);

void liberer_maillon(liste_navire l);

