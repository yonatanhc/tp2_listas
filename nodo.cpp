#include <iostream>
#include "nodo.h"

Nodo::Nodo(Trabajador* d){
	dato = d;
	siguiente = NULL;
}

void Nodo::cambiar_siguiente(Nodo* ps){
	siguiente = ps;
}

Trabajador* Nodo::obtener_dato(){
	return dato;
}

Nodo* Nodo::obtener_siguiente(){
	return siguiente;
}
