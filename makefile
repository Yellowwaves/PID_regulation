all: main autotests visualisationT consigne visualisationC regulation

main: main.c autotests.o visualisationT.o consigne.o visualisationC.o regulation.o
	gcc -o autotests main.c autotests.o visualisationT.o consigne.o visualisationC.o regulation.o -lm

autotests: autotests.c
	gcc -c autotests.c -o autotests.o -lm

visualisationT: visualisationT.c
	gcc -c visualisationT.c -o visualisationT.o

consigne: consigne.c
	gcc -c consigne.c -o consigne.o -lm

visualisationC: visualisationC.c
	gcc -c visualisationC.c -o visualisationC.o

regulation: regulation.c
	gcc -c regulation.c -o regulation.o

clean:
	rm -f main autotests.o visualisationT.o consigne.o visualisationC.o regulation.o

