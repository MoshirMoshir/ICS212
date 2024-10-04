JNI=/usr/java/default/include/
JNI_LINUX=/usr/java/default/include/linux

libhomework10.so: homework10.c homework10.h
	gcc -o libhomework10.so -shared -fPIE -I$(JNI) -I$(JNI_LINUX) homework10.c

homework10.o : homework10.c homework10.h
	gcc -ansi -pedantic-errors -Wall -c driver.c homework10.c

homework10.h : homework10.class
	javah homework10

homework10.class : homework10.java
	javac homework10.java