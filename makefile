All: main

main: main.o Matrice.o MatPleine.o MatCreuse.o
g++ -o main main.o Matrice.o MatPleine.o MatCreuse.o

main.o: main.cpp Matrice.h MatPleine.h
g++ -c main.cpp

Matrice.o: Matrice.cpp Matrice.h MatCreuse.h MatPleine.h
g++ -c Matrice.cpp

MatCreuse.o: MatCreuse.cpp MatCreuse.h MatPleine.h
g++ -c MatCreuse.cpp

MatPleine.o: MatPleine.cpp MatPleine.h MatCreuse.h
g++ -c MatPleine.cpp

clean:
rm -f *.o

mrproper: clean
rm -f main
