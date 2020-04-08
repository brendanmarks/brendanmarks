polyapp: polyapp.o poly.o utils.o utils.h poly.h
	gcc -o polyapp polyapp.o poly.o utils.o utils.h poly.h

polyapp.o: polyapp.c utils.h poly.h
	gcc -c polyapp.c utils.h poly.h

poly.o: poly.c utils.h
	gcc -c poly.c utils.h

utils.o: utils.c
	gcc -c utils.c

