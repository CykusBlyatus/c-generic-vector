PROGRAMS=1simple 2function

CFLAGS=-Wall -Wextra -Werror -I.

all: $(PROGRAMS)
	@echo "Programs ready!"

%: examples/%.c vector.h vector.o
	$(CC) $(CFLAGS) $< vector.o -o $@

vector.o: vector.h vector.c
	$(CC) -c $(CFLAGS) vector.c -o vector.o

clean:
	rm *.o $(PROGRAMS)
