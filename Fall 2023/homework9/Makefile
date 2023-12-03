homework9 : main.o Pokemon.o Dragapult.o Gardevoir.o Pikachu.o
	g++ -o project main.o Pokemon.o Dragapult.o Gardevoir.o Pikachu.o

main.o : user_interface.cpp llist.h record.h
	g++ -ansi -pedantic-errors -Wall -c user_interface.cpp

Pokemon.o : Pokemon.cpp Pokemon.h 
	g++ -ansi -pedantic-errors -Wall -c Pokemon.cpp

Dragapult.o : Dragapult.cpp Dragapult.h 
	g++ -ansi -pedantic-errors -Wall -c Dragapult.cpp

Gardevoir.o : Gardevoir.cpp Gardevoir.h 
	g++ -ansi -pedantic-errors -Wall -c Gardevoir.cpp

Pikachu.o : Pikachu.cpp Pikachu.h 
	g++ -ansi -pedantic-errors -Wall -c Pikachu.cpp
