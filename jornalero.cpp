#include <iostream>
#include "jornalero.h"


Jornalero::Jornalero(int legajo,string nombre):Trabajador(legajo, nombre){
	sueldo_diario = 0;
	cantidad_dias = 0;
}

void Jornalero::asignar_sueldo_diario(float sueldo_diario){
	this->sueldo_diario = sueldo_diario;
}

void Jornalero::asignar_dias_trabajados(int dias_trabajados){
	cantidad_dias = dias_trabajados;
}

float Jornalero::liquidar_sueldo(){
	return sueldo_diario * cantidad_dias;
}

void Jornalero::a_cadena(){
	cout << "----------------------" << endl;
	cout << "Legajo "<<"  "<< legajo << endl;
	cout << "Nombre "<<"  "<< nombre << endl;
	cout << "Tipo de trabajador"<<" Jornalero"<< endl;
	cout << "Sueldo diario"<<"  "<< sueldo_diario << endl;
	cout << "Cantidad de días trabajados"<<"  "<< cantidad_dias << endl;
	cout << "Liquidación del sueldo"<<"  "<< sueldo_a_cobrar << endl;
	cout << "----------------------" << endl;
}
