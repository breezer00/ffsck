all: monitor rand_flip

monito : monitor.c
	gcc -o monitor monitor.c

rand_flip : rand_flip.c 
	gcc -o rand_flip rand_flip.c

clean:
	rm monitor rand_flip
