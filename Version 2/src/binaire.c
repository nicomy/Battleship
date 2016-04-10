#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaire.h"


int get_field(uint32_t a, int faible, int fort){
	uint32_t tmp = a ;
	int bordg= 31 - fort ;

	tmp = tmp << bordg ; //on enlève tous les bits à gauche du bit fort
	tmp = tmp >> (bordg + faible-1) ; //puis on décalle jusqu'à que le bit faible soit au niveau du bit 0 afin qu'on puisse directement lire le bit.

	return tmp ; 
}

uint32_t set_field(uint32_t a, int faible, int fort , int v){
	uint32_t masque = ~0 ; // met masque à que des 1 
	int bordg = 31 - fort ; 

	masque = masque << bordg ; //on enlève tous 1 à gauche du bit fort
	masque = masque >> (bordg + faible-1) ;// enlève tous les 1 à droite de faible 
	masque = masque <<(faible -1); // replace le masque au debuté du bit faible
	v = v << (faible -1);  // on décale pareillement v pour être alligné avec les bon bit
	a = a & masque ; //on met à 0 tout les bits dans l'intervalle failbe-fort 
	a = a + v ; // on place les bit de v.
	//printf("%d\n", a);
	return a ; 
}

int get_i_deb(pMaillon m){
	//printf("get_i_deb %d\n", get_field(m->c, 0, 3));
	return get_field(m->c, 0, 3);
}

int get_i_fin(pMaillon m){
	//printf("get_i_fin %d\n", get_field(m->c, 14, 17));
	return get_field(m->c, 14, 17);
}

void set_i_deb(pMaillon m, int i){
	m->c = set_field(m->c, 0, 3, i);
}

void set_i_fin(pMaillon m, int i){
 	m->c = set_field(m->c, 14, 17, i);
}

int get_j_deb(pMaillon m){
	//printf("get_j_deb %d\n", get_field(m->c, 7, 10));
	return get_field(m->c, 7, 10);
}

int get_j_fin(pMaillon m){
	//printf("get_j_fin %d\n", get_field(m->c, 21, 24));
	return get_field(m->c, 21, 24);
}

void set_j_deb(pMaillon m, int j){
	m->c = set_field(m->c, 7, 10, j);
}

void set_j_fin(pMaillon m, int j){
	m->c = set_field(m->c, 21, 24, j);
}

void set_coule(pMaillon m, int v){
	m->c = set_field(m->c,31, 31, v);
}

int get_coule(pMaillon m){
	return get_field(m->c,31, 31);
}

