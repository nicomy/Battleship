#include "codageNavires.h"

void addNavire(pListe_navire list, pMaillon n){
	if (list->first == NULL){
		list->first = n;
		list->last = n;
	}
	else{
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

	set_i_deb(newNavire, i_first);
	set_j_deb(newNavire, j_first);
	set_i_fin(newNavire, i_end);
	set_j_fin(newNavire, j_end);
	set_coule(newNavire, 0);
	newNavire->nextMaillon = NULL;

	return newNavire;
}

pListe_navire liste_vide(){
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
		i--;
	}
	else if(j+1 < n){
		while(g[i][j] == 'N'){
			g[i][j] = 'o';
			j++;
		}
		j--;
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

char** cree_copie(grille g, int n){
	int i, j;
	grille copie = malloc(sizeof(char*)*n);
	if(copie == NULL){exit(0);}
	for (i = 0; i < n; ++i){
		copie[i] = malloc(sizeof(char)*n);
		if(copie[i] == NULL){exit(0);}
	}

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			copie[i][j] = g[i][j];
		}
	}

	return copie;

}

liste_navire cree_liste_navires(grille g, int n){

	int i, j;
	pListe_navire ln = liste_vide();
	pMaillon m;
	char** copie = cree_copie(g, n);
	for(i=0; i<n; i++){
		for (j = 0; j < n; j++){
			if(copie[i][j] == 'N'){
				m = find_navire(copie, n, i, j);
				//printGrille(g, n);
				addNavire(ln, m);
			}

		}
	}
	free(copie);
	return *ln;
}


int tailleNavire(pMaillon m){
	int res=0;
	if(get_i_deb(m) == get_i_fin(m)){
		res = get_j_fin(m) - get_j_deb(m)+1;
	}
	else{
		res = get_i_fin(m) - get_i_deb(m)+1;
	}

	return res;
}

int appartien(pMaillon current, int ic, int jc){
	int appartien = 0;
	int i, j;

	for (i = get_i_deb(current); i <= get_i_fin(current); i++){
		for(j=get_j_deb(current); j<=get_j_fin(current); j++){
			if(ic==i && jc == j){
				appartien=1;
			}
		}
	}
	
	return appartien;
}

void navireC(grille gc, pMaillon m){
	int i, j;
	for (i = get_i_deb(m); i <= get_i_fin(m); i++){
		for(j=get_j_deb(m); j<=get_i_fin(m); j++){
			gc[i][j] = 'C';
		}
	}
}

int navire_coule(maillon* m, int ic, int jc, grille gc){
	int i, j, counte=0, coule=0;
	pMaillon current = m;
	
	while(current != NULL && !appartien(current, ic, jc)){
		current = current->nextMaillon;	
	}

	if(current !=NULL){
		for(i=get_i_deb(current); i<=get_i_fin(current); i++){
			for (j=get_j_deb(current); j<=get_j_fin(current); j++){
				if(gc[i][j] == 'T'){
					counte++;
				}
			}
		}

		if(counte+1 >= tailleNavire(current)){
			coule=1;
			//printf("%d\n", current->i_fin);
			//printf("%d\n", current->j_fin);
			current->coule = 1;
			navireC(gc, current);
		}
	}
	return coule;
}


int jeu_fini(liste_navire l){
	int res=1;

	pMaillon current = l.first;
	while(current != NULL){
		if(get_coule(current) == 0){
			res = 0;
		}
		current = current->nextMaillon;
	}

	return res;
}

int navire_touche(grille g, int i, int j){
	return (g[i][j] == 'N');
}

void joue(grille g, grille gc, int n, liste_navire l, int i, int j){
	if(i>=n && j>=n){
		printf("rejouer\n");
	}
	else{
		if(navire_coule(l.first, i, j, gc)){
			printf("coule\n");
		}
		else if(navire_touche(g, i, j)){
			gc[i][j] = 'T';
			printf("touche\n");
		}
		else{
			gc[i][j] = 'X';
			printf("rate\n");
		}
	}
}

