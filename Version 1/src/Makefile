#mettre le Makfile dans le src
#faire le ex dans un autre Exec = 

SRCS = jeu.c affichage.c codageNavires.c main.c 
#SRCS = jeu.c affichage.c test_jeu.c
OBJS = $(SRCS:.c=.o)
CFLAGS= -I ../include -Wall 

all: test

test: $(OBJS)
	gcc  -g $(OBJS) -o bat

clean: 
	-rm *.o 