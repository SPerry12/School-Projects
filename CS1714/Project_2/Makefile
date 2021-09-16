$(CC) = gcc

final: main.o cards.o
	$(CC) main.o cards.o -o project3

main.o: main.c cards.h
	$(CC) -c main.c

cards.o: cards.c cards.h
	$(CC) -c cards.c

clean:
	rm *.o project3
