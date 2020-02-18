libtags.a: tags.o
	ar rc libtags.a tags.o

tags.o: tags.c
	$(CC) -c tags.c

clean:
	rm -f *.out *.o *.a