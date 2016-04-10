//Antoine Blanc et Nicolas Homberg
#include <stdio.h>
#include <stdlib.h>

typedef struct $maillon* pMaillon;
typedef struct $maillon
{
	int i_deb;
	int j_deb;
	int i_fin;
	int j_fin;
	int coule;
	pMaillon nextMaillon;
}maillon;



int get_i_deb(pMaillon m);
int get_i_fin(pMaillon m);
void set_i_deb(pMaillon m, int i);
void set_i_fin(pMaillon m, int i);
int get_j_deb(pMaillon m);
int get_j_fin(pMaillon m);
void set_j_deb(pMaillon m, int j);
void set_j_fin(pMaillon m, int j);
void set_coule(pMaillon m, int c);
int get_coule(pMaillon m);

/*
int get_field(uint32_t a, int faible, int fort);

int set_field(uint32_t a, int faible, int fort , int v);*/