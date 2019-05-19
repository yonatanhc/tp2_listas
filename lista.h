#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

class Lista{

	private:
		
		Nodo* primero;
		int tam;
	
	public:
		
		/*
        Descripción: Método constructor de lista.
        Precondiciones: -.
        Postcondiciones: Se inicializa el tamaño de la lista en cero y el puntero a nodo
        primero apunta a NULL.
        */
		Lista();
		
		/*
        Descripción: Agrega a la lista dinámica el trabajador que le llega como parámetro y aumenta en uno
        el tamaño de la lista dinámica.
        Precondiciones: El puntero a trabajador que llega corresponde a un trabajador válido.
        Postcondiciones: El trabajador que llega como parámetro del método es correctamente añadido a
        la lista dinámica, la cual se incrementa en uno.
        */
		void agregar(Trabajador* d);

		/*
        Descripción: Se devuelve el tamaño de la lista dinámica. 
        Precondiciones: -.
        Postcondiciones: El tamaño de la lista es devuelto.
        */
		int tamanio();

		
		/*
        Descripción: Elimina el nodo correspondiente al Trabajador cuyo legajo se pasa como parámetro del 
        método. Además, se decrementa la lista dinámica en uno. 
        Precondiciones: El legajo que le llega como parámetro pertenece al dominio del atributo legajo 
        de un objeto de clase Trabajador.
        Postcondiciones: Se pierde la dirección del nodo cuyo dato es el trabajador con el legajo pasado
        como parámetro del método y se disminuye el tamaño de la lista dinámica en uno.
        */
		bool dar_de_baja(int legajo);

		/*
        Descripción: Busca cual es el trabajador con el sueldo más alto y lo devuelve como un
        puntero. 
        Precondiciones: -.
        Postcondiciones: Se devuelve como puntero cual es el trabajador con el sueldo máximo. 
        */
		Trabajador* sueldo_maximo();

		/*
        Descripción: Busca cual es el trabajador con el sueldo más bajo y lo devuelve como un
        puntero. 
        Precondiciones: -.
        Postcondiciones: Se devuelve como puntero cual es el trabajador con el sueldo mínimo. 
        */
		Trabajador* sueldo_minimo();

		/*
        Descripción: Se encarga de sumar todos los sueldos de los trabajadores y devolver esto como
        valor de retorno del método. 
        Precondiciones: En caso de que la lista de trabajadores esté vacía, la suma de sueldos es cero.
        Postcondiciones: Se devuelve la suma de sueldos de todos los trabajadores de la lista.
        */
		float sumar_sueldo();

		/*
        Descripción: Devuelve un puntero al trabajador cuyo legajo se pasa como parámetro del método.
        Precondiciones: El legajo que se pasa como parámetro del método pertenece al dominio del atributo
        legajo de un objeto de clase Trabajador. En caso de que ningún trabajador tenga dicho legajo, se 
        devuelve NULL.
        Postcondiciones: Se devuelve el puntero al trabajador cuyo número de legajo es pasado como parámetro
        del método. 
        */
		Trabajador* consultar_legajo(int legajo);

		/*
        Descripción: Devuelve un puntero al trabajador que se encuentre en la posición de la lista dinámica
        que se pasa como parámetro del método.
        Precondiciones: La variable posición, pasada como parámetro, es mayor que cero y menor o igual al 
        tamaño total de la lista dinámica.
        Postcondiciones: El puntero al trabajador que se encuentra en la posición pasada como parámetro del 
        método es devuelto. 
        */
		Trabajador* obtener_trabajador(int posicion);

		/*
        Descripción: Método destructor de Lista. 
        Precondiciones: -.
        Postcondiciones: Libera toda la memoria que fue necesaria pedir al crear una lista. 
        */
		~Lista();

	private:
		
		/*
        Descripción: Devuelve un puntero al nodo cuya posición en la lista dinámica es pasada como parámetro 
        del método. 
        Precondiciones: La variable posición, pasada como parámetro, es mayor que cero y menor o igual al 
        tamaño total de la lista dinámica.
        Postcondiciones: Un puntero al nodo cuya posición en la lista dinámica es pasada como parámetro del 
        método es devuelto. 
        */
		Nodo* obtener_nodo(int posicion);

		/*
        Descripción: Devuelve true en caso de que la lista dinámica esté vacía o false en caso contrario.  
        Precondiciones: -.
        Postcondiciones: True si la lista dinámica se encuentra vacía o false si tiene uno o más nodos. 
        */
		bool lista_vacia();

};

#endif