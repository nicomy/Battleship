#mettre le Makfile dans le src
#faire le ex dans un autre Exec = 

SRCS = affichage.c test_affichage.c 
OBJS = $(SRCS:.c=.o)
CFLAGS= -I ../include -Wall 

all: affichage-test

affichage-test: $(OBJS)
	gcc  $(OBJS) -o aff

clean: 
	-rm *.o 