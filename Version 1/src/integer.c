//Antoine Blanc et Nicolas Homberg
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "integer.h"




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


