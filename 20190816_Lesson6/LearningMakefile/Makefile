CC=gcc
binary:mymath.o main.o
	$(CC) -o binary mymath.o main.o
mymath.o:mymath.c mymath.h
	$(CC) -c mymath.c
main.o:main.c
	$(CC) -c main.c
clean:
	rm main.o mymath.o binary
