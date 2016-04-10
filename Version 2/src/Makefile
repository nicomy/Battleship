#Antoine Blanc et Nicolas Homberg

SRCS = jeu.c affichage.c binaire.c codageNavires.c main.c 
OBJS = $(SRCS:.c=.o)
CFLAGS= -I ../include -Wall 

all: test

test: $(OBJS)
	gcc  -g $(OBJS) -o ../bin/bataille

clean: 
	-rm *.o 
