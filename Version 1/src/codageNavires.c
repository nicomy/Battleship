//Antoine Blanc et Nicolas Homberg
#include "codageNavires.h"

/**addNavire: ajout un  navire en fin de liste
*param:	list: structur de liste_navire
*		n: pointeur sur le maillon à a jouter
*return: retourne la liste de navire (structure liste_navire)
*/
liste_navire addNavire(liste_navire list, pMaillon n){
	if (list.first == NULL){
		list.first = n;
		list.last = n;
	}
	else{
		list.last->nextMaillon = n;
		list.last = n;
	}
	return list;
}

/**creatNavire: créer et initialise un navire
*param:	i_first: coordonée en i du début du bateau
*		j_first: coordonée en j du début du bateau
*		i_end: coordonée en i de la fin du bateau
*		j_end: coordonée en j de la fin du bateau
*return: retourne un point sur le maillon du navire créé
*/
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

/**cree une liste de navire vide (structure liste_navire)
*return: une liste vide
*/
liste_navire liste_vide(){
	liste_navire l; 
	l.first = NULL;
	l.last = NULL;
	return l;
}

/**trouve les beateaux dans la grille à partir du début du bateau. Et crée un maillon
*param:	g: grille de navire à trouver
*		n: taille de la grille
*		i: coordonnée en i du début du bateau
*		j: coordonnée en j du début du bateau
*return: retourne un pointeur sur le maillon crée pour le bateau trouvé
*/
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

/**printGrille affiche une grille (test)
*
*/
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

/**créé une copie d'un tableau
*param: g: grille a copier
*		n: taille de la grille a copier
return: retourne le tableau copié
*/
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

/**créé une liste de navire à partir de la grille J1
*param: g: grille de navire
*		n: taille de la grille
return: retourne la liste de navire
*/
liste_navire cree_liste_navires(grille g, int n){

	int i, j;
	liste_navire ln = liste_vide();
	pMaillon m;
	char** copie = cree_copie(g, n);
	for(i=0; i<n; i++){
		for (j = 0; j < n; j++){
			if(copie[i][j] == 'N'){
				m = find_navire(copie, n, i, j);
				//printGrille(g, n);
				ln = addNavire(ln, m);
			}

		}
	}
	free(copie);
	return ln;
}

/**calcul la taille d'un navire
*param: m: maillon du navire pour calculer ça taille
*return: retourne la taille du navire
*/
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

/**appartien: regarde si les coordonée apartienne à un bateau
*param:	current:maillon du beau à vérifier
*		ic: coordonée en i à vérifier
*		jc: coordonée en j à vérifier
*return: retourne 1 si les coordonée appartienne au bateau, 0 sinon 
*/
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

/**navireC: Met à jour la grille de J2 si le bateau est coulé
*param:	gc: grile de J2 à mettre a jour
		m:pointeur de maillon sur le bateau coulé
*/
void navireC(grille gc, pMaillon m){
	int i, j;
	for (i = get_i_deb(m); i <= get_i_fin(m); i++){
		for(j=get_j_deb(m); j<=get_j_fin(m); j++){
			gc[i][j] = 'C';
		}
	}
}

/**vérifie si le navire est coulé aprés une attaque
*param: m:pointeur sur le 1er maillon de la liste
*		ic: attaque en i du joueur J2
*		jc: attaque en j du joueur J2
*		gc: grille du jouer J2
*return: retourne 1 si un anvire est coulée, 0 sinon
*/
int navire_coule(maillon* m, int ic, int jc, grille gc){
	int i, j, counte=0, coule=0;
	pMaillon current = m;
	if(gc[ic][jc] != 'T'){
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
				current->coule = 1;
				navireC(gc, current);
			}
		}
	}
	return coule;
}

/**jeu_fini: permet de savoir lorsque tout les navire sont coulé
*param:	l: liste de navire
*return: retourne 1 si tout les navires sont coulé, 0 sinon
*/
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

/**navire_touche: vérifie si un navire est touché
*param: g: grille de J1
*		i: coordonée de l'ataque en i
*		j: coordonée de l'ataque en j
*return: retourne 1 si le navire est touché, 0 sinon
*/
int navire_touche(grille g, int i, int j){
	return (g[i][j] == 'N');
}

/**joue: permet à J2 de jouer une attaque
*param: g: grille de J1
*		gc: grille de J2
*		n:taille des grilles
*		l: liste de navire
*		i: attaque de J2 en i
*		j: attaque de J2 en j
*/
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

/**liberer_maillon: liber la liste liste de maillon
*param: l: liste de naivre;
*/
void liberer_maillon(liste_navire l){
	pMaillon pred = l.first;
	pMaillon current = l.first;

	while(current != NULL){
		current = current->nextMaillon;
		free(pred);
		pred = current;
	}

}