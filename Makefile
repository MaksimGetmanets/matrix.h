CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

LIB_NAME = matrix.a
all: matrix.o

$(LIB_NAME): matrix.o
	ar rcs $(LIB_NAME) matrix.o

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c -o matrix.o

clean:
	rm -rf *.o $(LIB_NAME)