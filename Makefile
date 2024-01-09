CFLAGS=-Wall -pedantic

all: morse clean

morse: morsecopy.o library.o
	gcc $^ -o $@
	
.PHONY: clean

clean:
	rm -rf *.o *~