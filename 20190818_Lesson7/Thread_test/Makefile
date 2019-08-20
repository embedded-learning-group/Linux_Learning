binary:main.o led.o
	gcc -o binary main.o led.o -lwiringPi -lpthread
main.o:main.c led.h
	gcc -c main.c -lwiringPi -lpthread
led.o:led.c
	gcc -c led.c -lwiringPi
clean:
	rm main.o led.o binary
