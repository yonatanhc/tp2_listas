#ifndef _MENU_H_
#define _MENU_H_

#include "lista.h"
#include "trabajador.h"
#include "empleado.h"
#include "jornalero.h"
#include "consultor.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const char TIPO_EMPLEADO = 'E';
const char TIPO_JORNALERO = 'J';
const char TIPO_CONSULTOR = 'C';

const char OPCION_CONSULTAR_LEGAJO = 'a';
const char OPCION_DAR_DE_BAJA = 'b';
const char OPCION_DE_ALTA = 'c';
const char OPCION_LISTAR_TRABAJADORES = 'd';
const char OPCION_SUELDO_MAXIMO = 'e';
const char OPCION_SUELDO_MINIMO = 'f';
const char OPCION_SUMAR_SUELDO = 'g';
const char OPCION_SALIR = 's';

const char MENU_ACTIVO = 'x'; // Este caracter es el que funciona como inicializador, es parte de las opciones que no hacen nada

class Menu{
    
    private:

        char opcion_usuario;
        Lista* lista_principal;

        /*
        Descripción: El usuario ingresa la opción del menú que desea y esta se guarda en el atributo opcion_usuario
        de un objeto de clase Menu.
        Precondiciones: -.
        Postcondiciones: La opción que el usuario ingresa es guardada correctamente en el atributo opcion_usuario. 
        */
        void recibir_opcion();

        /*
        Descripción: De acuerdo con la opción que ha ingresado el usuario, se ejecuta una cierta tarea correspondiente al menú.
        Precondiciones: La opción marcada por el usuario se encuentra dentro del dominio del atributo opcion_usuario.
        Postcondiciones: Una tarea puntual es realizada, de acuerdo con la opción ingresada por el usuario.
        */
        void ejecutar_opcion();

        /*
        Descripción: Se muestra una interfaz gráfica del Menú, además de dejar el atributo opcion_usuario en condición de activo. 
        Precondiciones: -.
        Postcondiciones: El usuario visualiza la interfaz gráfica del Menú y el atributo opcion_usuario se mantiene en condición 
        de activo. 
        */
        void mostrar_menu();

        /*
        Descripción: Se encarga de asignarle todos los correspondientes atributos a un empleado para luego agregarlo a la lista
        dinámica. 
        Precondiciones: Le llegan el empleado a agregar, junto con su sueldo mensual, llegadas tarde y ausencias. Estos últimos tres
        se encuentran dentro del dominio de los correspondientes atributos de un objeto de clase Empleado.
        Postcondiciones: Se carga correctamente un empleado junto con todos sus datos en la lista dinámica.
        */
        void cargar_empleado(Empleado* empleado,float sueldo_mensual,int llegadas_tarde,int ausencias);

        /*
        Descripción: Se encarga de asignarle todos los correspondientes atributos a un jornalero para luego agregarlo a la lista
        dinámica. 
        Precondiciones: Le llegan el jornalero a agregar, junto con su sueldo diario y dias trabajados. Estos últimos dos
        se encuentran dentro del dominio de los correspondientes atributos de un objeto de clase Jornalero.
        Postcondiciones: Se carga correctamente un jornalero junto con todos sus datos en la lista dinámica.
        */
        void cargar_jornalero(Jornalero* jornalero,float sueldo_diario,int dias_trabajados);

        /*
        Descripción: Se encarga de asignarle todos los correspondientes atributos a un consultor para luego agregarlo a la lista
        dinámica. 
        Precondiciones: Le llegan el consultor a agregar, junto con su sueldo de hora cátedra, la cantidad efectiva de horas cátedra
        y la cantidad de días a descontar. Estos últimos tres se encuentran dentro del dominio de los correspondientes atributos de 
        un objeto de clase Consultor.
        Postcondiciones: Se carga correctamente un consultor junto con todos sus datos en la lista dinámica.
        */
        void cargar_consultor(Consultor* consultor,float sueldo_hora_catedra,int cantidad_horas_catedra,int dias_a_descontar);

        /*
        Descripción: Lee todos los datos del archivo que le llega, identificando de qué tipo de trabajador se trata, para luego 
        agregar a este a la lista dinámica. 
        Precondiciones: Le llega por parámetro el archivo a analizar, el cual se encuentra correctamente formado y existe.
        Postcondiciones: Se leen efectivamente todos los datos del archivo para luego, según de qué tipo de trabajador se trate,
        agregar a éste a la lista de trabajadores dinámica.
        */
        void cargar_trabajador_desde_archivo(char const* archivo);

        /*
        Descripción: El usuario ingresa un número de legajo, y se comprueba si éste se encuentra en la lista dinámica, 
        indicándoselo en caso de que sea cierto, además de mostrarle todos los datos correspondientes a ese legajo. 
        Precondiciones: -.
        Postcondiciones: El usuario es informado si existe o no el legajo que ingresó.
        */
        void consultar_existencia_de_legajo();

        /*
        Descripción: Le pregunta al usuario cual número de legajo desea eliminar, y lo elimina efectivamente, en caso de 
        existir. 
        Precondiciones: -.
        Postcondiciones: Se da de baja el legajo que requiere el usuario.
        */
        void dar_de_baja_numero_legajo();

        /*
        Descripción: Le pregunta al usuario todos los datos correspondientes al trabajador que éste va a agregar, 
        y se lo agrega efectivamente a la lista dinámica.
        Precondiciones: -.
        Postcondiciones: Se agrega correctamente el trabajador requerido por el usuario, a la lista dinámica.
        */
        void menu_alta_trabajador();

        /*
        Descripción: Según el tipo de trabajador que le llega como parámetro del método, le pide al usuario que ingrese los 
        correspondientes valores de los atributos del tipo de trabajador, para luego cargarlo en la lista dinámica.  
        Precondiciones: Le llegan como parámetro el tipo de trabajador, el nombre de éste y el legajo. Éstos últimos dos, 
        deben pertenecer al dominio de los correspondientes atributos de un objeto de clase Trabajador.
        Postcondiciones: El usuario ingresa los correspondientes datos de un Trabajador y este se agrega a la lista dinámica.
        */
        void dar_de_alta_trabajador(char tipo_de_trabajador, string nombre, int legajo);

        /*
        Descripción: Se muestra por pantalla la lista de todos los trabajadores junto con sus correspondientes datos. 
        Precondiciones: En caso de que la lista esté vacía, no se imprime nada.
        Postcondiciones: El usuario visulaiza todos los trabajadores de lista, junto con sus correspondientes datos.
        */
        void listar_todos_los_trabajadores();

        /*
        Descripción: Se muestra por pantalla cual es el trabajador con el mayor sueldo de todos. 
        Precondiciones: En caso de haber dos trabajadores que tengan el sueldo máximo, solo se muestra al primero de estos.
        Postcondiciones: El usuario visualiza cual es el trabajador que presenta el mayor de los sueldos.
        */
        void indicar_sueldo_maximo();

        /*
        Descripción: Se muestra por pantalla cual es el trabajador con el menor sueldo de todos. 
        Precondiciones: En caso de haber dos trabajadores que tengan el sueldo mínimo, solo se muestra al primero de estos.
        Postcondiciones: El usuario visualiza cual es el trabajador que presenta el menor de los sueldos.
        */
        void indicar_sueldo_minimo();
            
        /*
        Descripción: Se muestra por pantalla cual es la sumatoria de todos los sueldos.  
        Precondiciones: La sumatoria de sueldos se dará en números enteros, no se considerarán decimales, debido a que resultan
        insignificantes en comparación con la sumatoria de muchos sueldos.
        Postcondiciones: El usuario visualiza cual es la sumatoria de todos los sueldos. 
        */
        void indicar_sumatoria_sueldo();

    public:

        /*
        Descripcion: Método Constructor de Menú.
        Precondiciones:-.
        Postcondiciones: El atributo opcion_usuario queda correctamente inicializado y se crea una lista dinámica.
        */
        Menu();

        /*
        Descripción: Inicia la interfaz del programa usando los métodos y clases necesarios para realizar la misma.
        Precondiciones: El archivo "trabajadores.txt" debe existir.
        Postcondiciones: Se muestra un menú mediante consola dando a elegir distintas opciones al usuario,
        el programa realizará las opciones del menú.
        */
        void iniciar_interfaz(char const* archivo); 

        /*
        Descripcion: Método Destructor de Menú.
        Precondiciones:-.
        Postcondiciones: Se libera toda la memoria que se pidió al crear un Menú.
        */
        ~Menu(); 
};

#endif /*_MENU_H_*/