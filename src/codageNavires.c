#include "codageNavires.h"

void addNavire(pListe_navire list, pMaillon* n){
	if (list->first == NULL){
		printf("prout1\n");
		list->first = n;
		list->last = n;
	}
	else{
		printf("prout2\n");
		(list)->last->nextMaillon = n;
		(list)->last = n;
	}
}

pMaillon creatNavire(int i_first, int j_first, int i_end, int j_end){
	pMaillon newNavire = malloc(sizeof(maillon));
	if(newNavire == NULL){
		printf("erreur d'alocation\n");
		exit(0);
	}

	newNavire->i_deb = i_first;
	newNavire->j_deb = j_first;
	newNavire->i_fin = i_end;
	newNavire->j_fin = j_end;
	newNavire->coule = 0;
	newNavire->nextMaillon = NULL;

	return newNavire;
}

pListe_navire creatList(){
	pListe_navire l = malloc(sizeof(liste_navire));
	if(l == NULL){
		printf("erreur d'alocation\n");
		exit(0);
	}
	l->first = NULL;
	l->last = NULL;
	return l;
}

pMaillon find_navire(grille g, int n, int i, int j){
	int i_first, j_first;
	i_first = i;
	j_first = j;

	if(i+1 < n && g[i+1][j] == 'N'){
		while(g[i][j] == 'N'){
			g[i][j] = 'o';
			i++;
		}
	}
	else if(j+1 < n){
		while(g[i][j] == 'N'){
			g[i][j] = 'o';
			j++;
		}
	}

	return creatNavire(i_first, j_first, i, j);
	
}

void printGrille(grille g, int taille){
	int i, j;
	for ( i = 0; i < taille; ++i)
	{
		for (j = 0; j < taille; ++j)
		{
			printf("%c ", g[i][j]);
		}
		printf("\n");
	}
}

liste_navire cree_liste_navires(grille g, int n){

	int i, j;
	pListe_navire ln = creatList();
	pMaillon m;

	for(i=0; i<n; i++){
		for (j = 0; j < n; j++){
			if(g[i][j] == 'N'){
				m = find_navire(g, n, i, j);
				printf("hey2\n");
				printGrille(g, n);
				addNavire(ln, m);
				printf("hey3\n");
			}

		}
	}
}
