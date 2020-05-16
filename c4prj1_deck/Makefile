CFLAGS= -ggdb3 -Wall -Werror -pedantic -std=gnu99 -g

test-deck: deck.o eval.o cards.o test-deck.o
	gcc -o test-deck test-deck.c deck.o eval.o cards.o $(CLAGS) 

deck.o: deck.c
	gcc -c deck.c $(CFLAGS)

eval.o: eval.c
	gcc -c eval.c $(CFLAGS)

cards.o: cards.c
	gcc -c cards.c $(CFLAGS)

test-deck.o: test-deck.c
	gcc -c test-deck.c $(CFLAGS)

deck.o:deck.h
eval.o:eval.h
cards.o:cards.h
