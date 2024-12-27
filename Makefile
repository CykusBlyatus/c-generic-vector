EXAMPLES=$(wildcard examples/*.c)
PROGRAMS=$(EXAMPLES:examples/%.c=bin/%)

CFLAGS=-Wall -Wextra -Werror -I.

all: $(PROGRAMS)
	@echo "Programs ready!"

bin/%: examples/%.c vector.h obj/vector.o
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< obj/vector.o -o $@

obj/vector.o: vector.h vector.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) vector.c -o $@

clean:
	rm -r obj/ bin/
