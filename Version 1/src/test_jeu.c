#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <jeu.h>

int main(int argc, char const *argv[])
{
	pbateau l ; 
	l = initbat();
	//printf("%d\n",l->nombre );
	//printf("%d\n", enlever(l)->nombre ) ;
	l=enlever(l);
	printf("%d\n",l->nombre );

	return 0;
}