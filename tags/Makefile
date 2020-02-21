default: all

all: libtags.a harness.o man_pages

harness.o: harness.h harness.c
	$(CC) -c harness.c harness.h

libtags.a: tags.o
	ar rc libtags.a tags.o

tags.o: tags.c tags.h
	$(CC) -c tags.c

man_pages:
	sudo cp set_tag.2 /usr/share/man/man2/
	sudo ln /usr/share/man/man2/set_tag.2 /usr/share/man/man2/get_tag.2
	sudo cp set_tag.3 /usr/share/man/man3/
	sudo ln /usr/share/man/man3/set_tag.3 /usr/share/man/man3/get_tag.3
	sudo cp harness_tag.3 /usr/share/man/man3/
	sudo ln /usr/share/man/man3/harness_tag.3 /usr/share/man/man3/retrieve_set_tag_params.3
	sudo ln /usr/share/man/man3/harness_tag.3 /usr/share/man/man3/retrieve_get_tag_params.3
	sudo ln /usr/share/man/man3/harness_tag.3 /usr/share/man/man3/interpret_set_tag_result.3
	sudo ln /usr/share/man/man3/harness_tag.3 /usr/share/man/man3/interpret_get_tag_result.3

clean:
	rm -f *.out *.o *.a *.gch
