CC = g++
CFLAGS = -g -std=c++11 -Wall -Werror -pedantic 
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

CFILES = main.cpp trabajador.cpp empleado.cpp jornalero.cpp consultor.cpp menu.cpp nodo.cpp lista.cpp
HFILES = menu.h trabajador.h empleado.h jornalero.h consultor.h nodo.h lista.h
EXEC_S = pruebas

CPARAMETRO = trabajadores.txt

build: $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o $(EXEC_S) 

run: build
	./$(EXEC_S) $(CPARAMETRO)

valgrind: build
	valgrind $(VFLAGS) ./$(EXEC_S)

gdb: build
	gdb $(GDBFLAGS) ./$(EXEC_S)
