#ifndef CONSULTOR_H
#define CONSULTOR_H

#include <string>
#include "trabajador.h"
using namespace std;

class Consultor: public Trabajador{
	
	private:
		
		float valor_hora_catedra;
		int cantidad_horas_catedra;
		int horas_a_descontar;

	public:

		/*
    	Descripción: Método Constructor de Consultor.
    	Precondiciones: Le llegan el legajo a ingresar y el nombre a ingresar. Ambas variables deben encontrarse
    	dentro del dominio de los correspondientes atributos de un objeto de clase Trabajador.
    	Postcondiciones: Los atributos valor_hora_catedra, cantidad_horas_catedra y horas_a_descontar de un objeto de 
    	clase Consultor son inicializados en cero. Además, se crea un objeto de clase Trabajador simultáneamente.
    	*/
		Consultor(int legajo,string nombre);
		
		/*
    	Descripción: El atributo valor_hora_catedra de un objeto de clase Consultor es asignado con el valor
    	de la variable pasada como parámetro "valor_hora_catedra". 
   		Precondiciones: La variable pasada como parámetro "valor_hora_catedra" se encuentra dentro del dominio
    	del atributo valor_hora_catedra de un objeto de clase Consultor.
    	Postcondiciones: El nuevo valor del atributo valor_hora_catedra de un objeto de clase Consultor es igual
    	al valor de la variable pasada como parámetro "valor_hora_catedra".
		*/	
		void asignar_sueldo_hora_catedra(float valor_hora_catedra);
       
       	/*
    	Descripción: El atributo cantidad_horas_catedra de un objeto de clase Consultor es asignado con el valor
    	de la variable pasada como parámetro "cantidad_horas_catedra". 
   		Precondiciones: La variable pasada como parámetro "cantidad_horas_catedra" se encuentra dentro del dominio
    	del atributo cantidad_horas_catedras de un objeto de clase Consultor.
    	Postcondiciones: El nuevo valor del atributo cantidad_horas_catedra de un objeto de clase Consultor es igual
    	al valor de la variable pasada como parámetro "cantidad_horas_catedra".
		*/	
        void asignar_cantidad_horas_catedra(int cantidad_horas_catedra);
        
        /*
    	Descripción: El atributo horas_a_descontar de un objeto de clase Consultor es asignado con el valor
    	de la variable pasada como parámetro "horas_a_descontar". 
   		Precondiciones: La variable pasada como parámetro "horas_a_descontar" se encuentra dentro del dominio
    	del atributo horas_a_descontar de un objeto de clase Consultor.
    	Postcondiciones: El nuevo valor del atributo horas_a_descontar de un objeto de clase Consultor es igual
    	al valor de la variable pasada como parámetro "horas_a_descontar".
		*/	
        void asignar_horas_a_descontar(int horas_a_descontar);
        
       	/*
   		Descripción: Devuelve el sueldo bruto a cobrar por un Consultor luego de un mes de trabajo. 
    	Precondiciones: -.
    	Postcondiciones: El sueldo bruto a cobrar por un Consultor es devuelto.
		*/	
      	float liquidar_sueldo();
        
        /*
   	 	Descripción: Se muestran por pantalla todos los datos correspondientes a un Consultor. 
    	Precondiciones: -.
    	Postcondiciones: Todos los datos correspondientes a un Consultor son mostrados por pantalla.
		*/	
        void a_cadena();

       

};

#endif