CC=g++
CFLAGS= -W -Wall -ansi -pedantic
LDFLAGS=
EXEC=GestEleve
all:$(EXEC)

GestEleve: application.o main.o eleve.o matiere.o section.o 
	$(CC) -o GestEleve application.o main.o eleve.o matiere.o section.o 

application.o: application.cpp
	$(CC) -o application.o -c application.cpp $(CFLAGS)

main.o: main.cpp
	$(CC) -o main.o -c main.cpp $(CFLAGS)

eleve.o: eleve.cpp
	$(CC) -o eleve.o -c eleve.cpp $(CFLAGS)

matiere.o: matiere.cpp
	$(CC) -o matiere.o -c matiere.cpp $(CFLAGS)

section.o: section.cpp
	$(CC) -o section.o -c section.cpp $(CFLAGS)



clean:
	rm -rf *.o

mrproper: clean
	rm -rf GestEleve