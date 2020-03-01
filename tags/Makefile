default: libtags.a

libtags.a: tags.o harness.o
	ar rc libtags.a tags.o harness.o

harness.o: harness.h harness.c
	$(CC) -c harness.c harness.h

tags.o: tags.c tags.h
	$(CC) -c tags.c

install: libtags.a harness.h tags.h set_tag.2 set_tag.3 harness_tag.3
	mkdir -p /usr/include/tags
	cp tags.h /usr/include/tags
	cp harness.h /usr/include/tags
	cp libtags.a /usr/lib/x86_64-linux-gnu
	cp set_tag.2 /usr/share/man/man2/
	ln /usr/share/man/man2/set_tag.2 /usr/share/man/man2/get_tag.2
	cp set_tag.3 /usr/share/man/man3/
	ln /usr/share/man/man3/set_tag.3 /usr/share/man/man3/get_tag.3
	cp harness_tag.3 /usr/share/man/man3/
	ln /usr/share/man/man3/harness_tag.3 /usr/share/man/man3/retrieve_set_tag_params.3
	ln /usr/share/man/man3/harness_tag.3 /usr/share/man/man3/retrieve_get_tag_params.3
	ln /usr/share/man/man3/harness_tag.3 /usr/share/man/man3/interpret_set_tag_result.3
	ln /usr/share/man/man3/harness_tag.3 /usr/share/man/man3/interpret_get_tag_result.3

clean:
	rm -f *.out *.o *.a *.gch