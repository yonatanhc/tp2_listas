#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include "trabajador.h"

using namespace std;

class Empleado: public Trabajador{
	
	private:

		float sueldo_mensual;
		int llegadas_tarde;
		int ausencias;

	public:

		/*
    	Descripción: Método Constructor de empleado.
    	Precondiciones: Le llegan el legajo a ingresar y el nombre a ingresar. Ambas variables deben encontrarse
    	dentro del dominio de los correspondientes atributos de un objeto de clase Trabajador.
    	Postcondiciones: Los atributos sueldo_mensual, llegadas_tarde y ausencias de un objeto de clase Empleado son 
    	inicializados en cero. Además, se crea un objeto de clase Trabajador simultáneamente.
    	*/
		Empleado(int legajo,string nombre);       
        
        /*
    	Descripción: El atributo sueldo_mensual de un objeto de clase Empleado es asignado con el valor
    	de la variable pasada como parámetro "sueldo_mensual". 
   		Precondiciones: La variable pasada como parámetro "sueldo_mensual" se encuentra dentro del dominio
    	del atributo sueldo_mensual de un objeto de clase Empleado.
    	Postcondiciones: El nuevo valor del atributo sueldo_mensual de un objeto de clase Empleado es igual
    	al valor de la variable pasada como parámetro "sueldo_mensual".
		*/	
        void asignar_sueldo_mensual(float sueldo_mensual);
        
        /*
    	Descripción: El atributo llegadas_tardes de un objeto de clase Empleado es asignado con el valor
    	de la variable pasada como parámetro "llegadas_tarde". 
   		Precondiciones: La variable pasada como parámetro "llegadas_tarde" se encuentra dentro del dominio
    	del atributo llegadas_tarde de un objeto de clase Empleado.
    	Postcondiciones: El nuevo valor del atributo llegadas_tarde de un objeto de clase Empleado es igual
    	al valor de la variable pasada como parámetro "llegadas_tarde".
		*/	
        void asignar_llegadas_tarde(int llegadas_tarde);
        
        /*
    	Descripción: El atributo ausencias de un objeto de clase Empleado es asignado con el valor
    	de la variable pasada como parámetro "ausencias". 
   		Precondiciones: La variable pasada como parámetro "ausencias" se encuentra dentro del dominio
    	del atributo ausencias de un objeto de clase Empleado.
    	Postcondiciones: El nuevo valor del atributo ausencias de un objeto de clase Empleado es igual
    	al valor de la variable pasada como parámetro "ausencias".
		*/	
        void asignar_ausencias(int ausencias);
		
		/*
   		Descripción: Devuelve el sueldo bruto a cobrar por un Empleado luego de un mes de trabajo. 
    	Precondiciones: -.
    	Postcondiciones: El sueldo bruto a cobrar por un Empleado es devuelto.
		*/	
		float liquidar_sueldo();
		
		/*
   	 	Descripción: Se muestran por pantalla todos los datos correspondientes a un Empleado. 
    	Precondiciones: -.
    	Postcondiciones: Todos los datos correspondientes a un Empleado son mostrados por pantalla.
		*/	
		void a_cadena();

	
};

#endif