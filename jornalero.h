#ifndef JORNALERO_H
#define JORNALERO_H
#include <string>
using namespace std;

#include "trabajador.h"

class Jornalero: public Trabajador{

	private:

		float sueldo_diario;
		int cantidad_dias;

	public:

	/*
    Descripción: Método Constructor de jornalero.
    Precondiciones: Le llegan el legajo a ingresar y el nombre a ingresar. Ambas variables deben encontrarse
    dentro del dominio de los correspondientes atributos de un objeto de clase Trabajador.
    Postcondiciones: Los atributos sueldo_diario y cantidad_dias de un objeto de clase Jornalero son 
    inicializados en cero. Además, se crea un objeto de clase Trabajador simultáneamente.
    */
	Jornalero(int legajo,string nombre);
	
	/*
    Descripción: El atributo sueldo_diario de un objeto de clase Jornalero es asignado con el valor
    de la variable pasada como parámetro "sueldo_diario". 
    Precondiciones: La variable pasada como parámetro "sueldo_diario" se encuentra dentro del dominio
    del atributo sueldo_diario de un objeto de clase Jornalero.
    Postcondiciones: El nuevo valor del atributo sueldo_diario de un objeto de clase Jornalero es igual
    al valor de la variable pasada como parámetro "sueldo_diario".
	*/	
	void asignar_sueldo_diario(float sueldo_diario);
    
	/*
    Descripción: El atributo cantidad_dias de un objeto de clase Jornalero es asignado con el valor
    de la variable pasada como parámetro "dias_trabajados". 
    Precondiciones: La variable pasada como parámetro "dias_trabajados" se encuentra dentro del dominio
    del atributo cantidad_dias de un objeto de clase Jornalero.
    Postcondiciones: El nuevo valor del atributo cantidad_dias de un objeto de clase Jornalero es igual
    al valor de la variable pasada como parámetro "dias_trabajados".
	*/	
    void asignar_dias_trabajados(int dias_trabajados);
	
	/*
    Descripción: Devuelve el sueldo bruto a cobrar por un Jornalero luego de un mes de trabajo. 
    Precondiciones: -.
    Postcondiciones: El sueldo bruto a cobrar por un Jornalero es devuelto.
	*/	
	float liquidar_sueldo();
	
	/*
    Descripción: Se muestran por pantalla todos los datos correspondientes a un Jornalero. 
    Precondiciones: -.
    Postcondiciones: Todos los datos correspondientes a un Jornalero son mostrados por pantalla.
	*/	
	void a_cadena();

   
	
};

#endif