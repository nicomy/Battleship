#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "binaire.h"


/*int get_field(uint32_t a, int faible, int fort){
	uint32_t tmp = a ;
	int bordg= 31 - fort ;

	tmp = tmp << bordg ;
	tmp = tmp >> (bordg + faible) ;

	return tmp ; 
}

int set_field(uint32_t a, int faible, int fort , int v){
	uint32_t masque = ~0 ;
	int bordg = 31 - fort ; 

	masque = masque << bordg ; 
	masque = masque >> (bordg + faible) ;
	masque = masque <<faible ;
	masque = ~masque ;
	v = v << faible ; 
	a = a & masque ; 
	a = a + v ; 
	return a ; 
}*/

int get_i_deb(pMaillon m){
	return m->i_deb;
}

int get_i_fin(pMaillon m){
	return m->i_fin;
}

void set_i_deb(pMaillon m, int i){
	m->i_deb = i;
}

void set_i_fin(pMaillon m, int i){
 	m->i_fin = i;
}

int get_j_deb(pMaillon m){
	return m->j_deb;
}

int get_j_fin(pMaillon m){
	return m->j_fin;
}

void set_j_deb(pMaillon m, int j){
	m->j_deb = j;
}

void set_j_fin(pMaillon m, int j){
	m->j_fin = j;
}

void set_coule(pMaillon m, int c){
	m->coule = c;
}

int get_coule(pMaillon m){
	return m->coule;
}

/*
int main(int argc, char const *argv[])
{
	uint32_t a,b = 256 + 2048  +15 + 40100;
	//b  ;
	printf("%d\n",b );
	printf("%d\n", get_field(b,8,11) ); 
	printf("%d\n", b );
	a = set_field(b,8,10,11);
	printf("%d\n", a );
	printf("%d\n", get_field(a,8,11) );
	




	return 0;
}
*/