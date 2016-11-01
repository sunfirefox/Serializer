CC=gcc
CFLAGS=-g
PROGRAM=example
LIB=libserializer.a

all: $(PROGRAM) $(LIB)

example: main.o boolean.h serializer.h libserializer.a
	$(CC) $(CFLAGS) -static main.o -L. -lserializer -lm -o example

main.o: main.c boolean.h serializer.h
	$(CC) -c main.c

libserializer.a: serializer.o boolean.h serializer.h
	ar rcs libserializer.a serializer.o

serializer.o: serializer.c boolean.h serializer.h
	$(CC) -c serializer.c

clean:
	rm -f *.o &> /dev/null
