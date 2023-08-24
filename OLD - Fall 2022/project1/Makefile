user_interface : user_interface.o database.o database.h record.h
	gcc -o project user_interface.o database.o

user_interface.o : user_interface.c
	gcc -ansi -pedantic-errors -Wall -c user_interface.c

database.o : database.c
	gcc -ansi -pedantic-errors -Wall -c database.c
