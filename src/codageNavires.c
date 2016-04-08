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
	pListe_navire ln = creatList();
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
	int res;
	if(m->i_deb == m->i_fin){
		res = m->j_fin - m->j_deb;
	}
	else{
		res = m->i_fin - m->i_deb;
	}
	return res;
}

int appartien(pMaillon current, int ic, int jc){
	int appartien = 0;
	int i, j;
	for (i = i_deb; i <= current->i_fin; j++){
		for(j=j_deb; j<=current->j_fin; j++){
			if(ic==i && jc == j){
				appartien=1;
			}
		}
	}
	return appartien;
}

void navireC(grille gc, pMaillon m){
	int i, j;
	for (i = i_deb; i <= current->i_fin; j++){
		for(j=j_deb; j<=current->j_fin; j++){
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
		for(i=m->i_deb; i<=m->i_fin; i++){
			for (j=m->j_deb; j<=m->j_fin; j++){
				if(gc[i][j] == 'T'){
					counte++;
				}
			}
		}
		if(counte+1 >= tailleNavire(current)){
			coule=1;

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
		if(current->coule == 0){
			res = 0;
		}
		current = current->nextMaillon;
	}

	return res;
}

