#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <string>
using namespace std;

class Trabajador{

	protected:
		
		int legajo;
		string nombre;
		float sueldo_a_cobrar;
		
	public:

		/*
        Descripción: Método Constructor de trabajador.
        Precondiciones: Le llegan el legajo a ingresar y el nombre a ingresar. Ambas variables deben encontrarse
        dentro del dominio de los correspondientes atributos de un objeto de clase Trabajador.
        Postcondiciones: El atributo legajo de un objeto de clase Trabajador es inicializado con el valor de la 
        variable pasada como parámetro "legajo". El atributo nombre de un objeto de clase Trabajador es inicializado 
        con el valor de la variable pasada como parámetro "nombre". Mientras que el atributo sueldo_a_cobrar es 
        inicializado en cero.  
        */
		Trabajador(int legajo, string nombre);
		
		/*
        Descripción: Se devuelve el atributo legajo de un objeto de clase Trabajador.  
        Precondiciones: -.
        Postcondiciones: El valor del atributo legajo de un objeto de clase Trabajador es devuelto. 
        */
		int obtener_legajo();
		
		/*
        Descripción: El atributo sueldo_a_cobrar de un objeto de clase Trabajador es igualado al valor
        de la variable pasada como parámetro "nuevo_sueldo".   
        Precondiciones: La variable nuevo_sueldo se encuentra dentro del dominio del atributo sueldo_a_cobrar
        de un objeto de clase Trabajador.
        Postcondiciones: El nuevo sueldo es asignado al atributo sueldo_a_cobrar de un objeto de clase Trabajador.
        */
		void asignar_sueldo_a_cobrar(float nuevo_sueldo);
		
		/*
        Descripción: Se devuelve el valor del atributo sueldo_a_cobrar de un objeto de clase Trabajador.  
        Precondiciones: -.
        Postcondiciones: El valor del atributo sueldo_a_cobrar de un objeto de clase Trabajador es devuelto. 
        */
		float obtener_sueldo_a_cobrar();

		/*
        Descripción: Método virtual que es redefinido en las clases derivadas de Trajador. En este clase, 
        particularmente no realiza ninguna tarea.  
        Precondiciones: -.
        Postcondiciones: -. 
        */
		virtual float liquidar_sueldo() = 0;
		
		/*
        Descripción: Método virtual que es redefinido en las clases derivadas de Trajador. En este clase, 
        particularmente no realiza ninguna tarea.  
        Precondiciones: -.
        Postcondiciones: -. 
        */
		virtual void a_cadena() = 0;
                
                virtual ~Trabajador() = 0;
};

#endif