all : projet_c

projet_c : test_simulateur.o visualisationT.o visualisationC.o regulation.o consigne.o simulateur.o
	gcc -o test_simulateur test_simulateur.o visualisationT.o visualisationC.o regulation.o consigne.o simulateur.o

visualisationT.o : visualisationT.c visualisationT.h
	gcc -c visualisationT.c


visualisationC.o : visualisationC.c visualisationC.h
	gcc -c visualisationC.c

regulation.o : regulation.c regulation.h
	gcc -c regulation.c

consigne.o : consigne.c consigne.h
	gcc -c consigne.c

test_simulateur.o : test_simulateur.c simulateur.h visualisationT.h visualisationC.h regulation.h consigne.h 
	gcc -c test_simulateur.c

simulateur.o: simulateur.c simulateur.h
	gcc -c simulateur.c

clean : 
	rm *.o
