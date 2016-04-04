
void addNavire(pList_navire* list, pMaillon* n){
	if (list == NULL){
		list->first = n;
		list->last = n;
	}
	else{
		(*list)->last->nextMailloin = n;
		(*list)->last = n;
	}
}

pNavire creatNavire(int i_first, int j_first, int i_end, int j_end){
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
	newNavire->newNavire = NULL;

	return newNavire;
}

pList creatList(){
	pList_navire l = malloc(sizeof(list_navire));
	l->first = NULL;
	l->last = NULL
	return l;
}

pMaillon find_navire(grille* g, int n, int i, int j){
	int i_first, j_first, i_end, j_end;
	i_first = i;
	j_first = j;

	if(g[i+1][j] == N){
		while(g[i][j] == N){
			g[i][j] = 'o';
			i++;
		}
	}
	else{
		while(g[i][j] == N){
			g[i][j] = 'o';
			j++;
		}
	}

	return creatNavire(i_first, j_first, i, j);
	
}

list_navire cree_liste_navires(grille g, int n){

	int i, j;
	pList_navire ln = creatList;
	pMaillon m;

	for(i=0; i<n; i++){
		for (int j = 0; j < n; j++){
			if(g[i][j] == N){
				m = find_navire(&g, n);
				addNavire(ln, m);
			}

		}
	}
}
