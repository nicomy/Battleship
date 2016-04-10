#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>



int get_field(uint32_t a, int faible, int fort){
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
}

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