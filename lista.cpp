#include <iostream>
#include "lista.h"


Lista::Lista(){
	primero = NULL;
	tam = 0;
}

void Lista::agregar(Trabajador* dato){
	Nodo* nuevo_nodo = new Nodo(dato);
	if(lista_vacia()){
		primero = nuevo_nodo;
	}
	else{
		if(dato->obtener_legajo() < primero->obtener_dato()->obtener_legajo()){
				nuevo_nodo->cambiar_siguiente(primero);
				primero = nuevo_nodo;
		}
		else{
			Nodo* actual = primero->obtener_siguiente();
			Nodo* anterior = primero;
			bool insertado = false;
			while(actual && !insertado){
				if(dato->obtener_legajo() < actual->obtener_dato()->obtener_legajo()){
					nuevo_nodo->cambiar_siguiente(actual);
					anterior->cambiar_siguiente(nuevo_nodo);
					insertado = true;
				}
				anterior = actual;
				actual = actual->obtener_siguiente();
			}
			if(!actual && !insertado){
				anterior->cambiar_siguiente(nuevo_nodo);
			}
		}
	}
	tam++;
}

int Lista::tamanio(){
	return tam;
}

bool Lista::lista_vacia(){
	return tam == 0;
}

bool Lista::dar_de_baja(int legajo){
	bool eliminado=false;
	if(!lista_vacia()){
		Nodo* aux = primero;
		if(aux->obtener_dato()->obtener_legajo() == legajo){
			primero = aux->obtener_siguiente();
			eliminado = true;
		}
		else{
			aux = aux->obtener_siguiente();
			Nodo* anterior = primero;
			eliminado = false;
			while(aux && !eliminado){
				if(aux->obtener_dato()->obtener_legajo() == legajo){
					anterior->cambiar_siguiente(aux->obtener_siguiente());
					eliminado = true;
				}
				else{
					anterior = aux;
					aux = aux->obtener_siguiente();
				}
			}
		}
		tam--;
	
		delete aux->obtener_dato();
		delete aux;

	}
	return eliminado;
}

Trabajador* Lista::sueldo_maximo(){
	float sueldo_maximo = primero->obtener_dato()->obtener_sueldo_a_cobrar();
	Trabajador* aux = primero->obtener_dato();
	Nodo* actual = primero->obtener_siguiente();
	while(actual){
		float sueldo = actual->obtener_dato()->obtener_sueldo_a_cobrar();
		if( sueldo > sueldo_maximo){ 
			sueldo_maximo = sueldo;
			aux = actual->obtener_dato();
		}
		actual = actual->obtener_siguiente();
	}
	return aux;
}

Trabajador* Lista::sueldo_minimo(){
	float sueldo_minimo = primero->obtener_dato()->obtener_sueldo_a_cobrar();
	Trabajador* aux = primero->obtener_dato();
	Nodo* actual = primero->obtener_siguiente();
	while(actual){
		float sueldo = actual->obtener_dato()->obtener_sueldo_a_cobrar();
		if( sueldo < sueldo_minimo){ 
			sueldo_minimo = sueldo;
			aux = actual->obtener_dato();
		}
		actual = actual->obtener_siguiente();
	}
	return aux;
}

float Lista::sumar_sueldo(){
	Nodo* actual = primero;
	float suma_sueldo = 0;
	while(actual){
		float sueldo = actual->obtener_dato()->obtener_sueldo_a_cobrar();
		suma_sueldo += sueldo;	
		actual = actual->obtener_siguiente();
	}
	return suma_sueldo;
}

Trabajador* Lista::consultar_legajo(int legajo){
	Nodo* actual = primero;
	while(actual){
		if(actual->obtener_dato()->obtener_legajo() == legajo){
			return actual->obtener_dato();
		}
		actual = actual->obtener_siguiente();
	}
	return NULL;
}

Nodo* Lista::obtener_nodo(int posicion){
	Nodo* aux = primero;
	for (int i = 1; i < posicion; i++){
		aux = aux->obtener_siguiente();
	}
	return aux;
}

Trabajador* Lista::obtener_trabajador(int posicion){
	return obtener_nodo(posicion)->obtener_dato();
}

Lista::~Lista(){
	
	while(!lista_vacia()){
		Nodo* aux = obtener_nodo(1);
		dar_de_baja(aux->obtener_dato()->obtener_legajo());
	}

}