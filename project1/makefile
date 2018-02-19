all: memgrind.o mymalloc.o
	gcc memgrind.o mymalloc.o mymalloc.h -g -o memgrind

memgrind.o: memgrind.c mymalloc.h
	gcc -c -g memgrind.c

mymalloc.o: mymalloc.c mymalloc.h
	gcc -c -g mymalloc.c

clean:
	rm memgrind memgrind.o mymalloc.o
