#mettre le Makfile dans le src
#faire le ex dans un autre Exec = 
#affichage.c jeu.c main.c test_codageNavire.c
SRCS = codageNavires.c affichage.c jeu.c main.c
OBJS = $(SRCS:.c=.o)
CFLAGS= -I ../include -Wall 

all: affichage-test

affichage-test: $(OBJS)
	gcc  $(OBJS) -o aff

clean: 
	-rm *.o 