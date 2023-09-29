echolor : main.o colors.o styles.o parser.o
	gcc -o ../echolor main.o colors.o styles.o parser.o

parser.o : utils/parser.c
	gcc -o parser.o -c utils/parser.c

styles.o : utils/styles.c
	gcc -o styles.o -c utils/styles.c

colors.o : utils/colors.c
	gcc -o colors.o -c utils/colors.c

main.o : main.c
	gcc -o main.o -c main.c

clean:
	rm -rf *.o
