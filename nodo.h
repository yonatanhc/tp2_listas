#ifndef NODO_H_
#define NODO_H_

#include "trabajador.h"

class Nodo{
	
	private:

		Trabajador* dato;
		Nodo* siguiente;
		
	public:
		
		/*
        Descripción: Método constructor de nodos. 
        Precondiciones: -.
        Postcondiciones: El dato del nodo se iguala al puntero a Trabajador pasado como parámetro
        del método "d". Además, el puntero a Nodo siguiente se iguala a NULL. 
        */
		Nodo(Trabajador* d);

		/*
        Descripción: Se iguala el puntero "siguiente" de un objeto de clase Nodo a otro puntero
        que es pasado como parámetro del método "ps".  
        Precondiciones: El puntero pasado como parámetro corresponde a una dirección de memoria válida.
        Postcondiciones: El puntero "siguiente" de un objeto de clase Nodo, ahora apunta a la dirección apuntada
        por el puntero pasado como parámetro "ps".
        */
		void cambiar_siguiente(Nodo* ps);

		/*
        Descripción: Se devuelve el dato almacenado por el nodo. Es decir, una dirección de un trabajador. 
        Precondiciones: -.
        Postcondiciones: La dirección del trabajador almacenada en el Nodo se devuelve como valor de retorno del 
        método. 
        */
		Trabajador* obtener_dato();

		/*
        Descripción: Se devuelve el puntero que apunta al siguiente nodo. 
        Precondiciones: -.
        Postcondiciones: El puntero al siguiente nodo es devuelto como valor de retorno del método.
        */
		Nodo* obtener_siguiente();

};

#endif
