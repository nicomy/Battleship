#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaire.h"


int get_field(uint32_t a, int faible, int fort){
	uint32_t tmp = a ;
	int bordg= 31 - fort ;

	tmp = tmp << bordg ;
	tmp = tmp >> (bordg + faible-1) ;

	return tmp ; 
}

uint32_t set_field(uint32_t a, int faible, int fort , int v){
	uint32_t masque = ~0 ;
	int bordg = 31 - fort ; 

	masque = masque << bordg ; 
	masque = masque >> (bordg + faible-1) ;
	masque = masque <<(faible -1);
	masque = ~masque ;
	v = v << (faible -1); 
	a = a & masque ; 
	a = a + v ; 
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

