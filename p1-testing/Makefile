CC=gcc

default: all

all: gettag.out settag.out


gettag.out: gettag.o
	$(CC) gettag.o -L./../tags -ltags -o gettag.out

gettag.o: gettag.c ./../tags/tags.h
	$(CC) -c gettag.c ./../tags/tags.h


settag.out: settag.o
	$(CC) settag.o -L./../tags -ltags -o settag.out

settag.o: settag.c ./../tags/tags.h
	$(CC) -c settag.c ./../tags/tags.h


clean:
	rm -f *.o *.a *.out
