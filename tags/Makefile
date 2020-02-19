default: all

all: libtags.a harness.o

harness.o: harness.h harness.c
	$(CC) -c harness.c harness.h

libtags.a: tags.o
	ar rc libtags.a tags.o

tags.o: tags.c tags.h
	$(CC) -c tags.c

clean:
	rm -f *.out *.o *.a