all: program

program: main.o Furniture.o Catalog.o AssocTab.o Menu.o Test.o
	g++ -o program main.o Furniture.o Catalog.o AssocTab.o Menu.o Test.o

main.o: main.cpp Furniture.h Catalog.h AssocTab.h Menu.h Test.h
	g++ -c main.cpp

Furniture.o: Furniture.cpp Furniture.h
	g++ -c Furniture.cpp

AssocTab.o: AssocTab.cpp AssocTab.h 
	g++ -c AssocTab.cpp

Catalog.o: Catalog.cpp Catalog.h Furniture.h AssocTab.h
	g++ -c Catalog.cpp

Menu.o: Menu.cpp Menu.h Catalog.h Furniture.h AssocTab.h
	g++ -c Menu.cpp

Test.o: Test.cpp Test.h Catalog.h Furniture.h AssocTab.h
	g++ -c Test.cpp

clean:
	rm -rf *o program
