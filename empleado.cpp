#include <iostream>
#include "empleado.h"

Empleado::Empleado(int legajo,string nombre):Trabajador(legajo,nombre){
	sueldo_mensual = 0;
	llegadas_tarde = 0;
	ausencias = 0;
}

void Empleado::asignar_sueldo_mensual(float sueldo_mensual){
	this->sueldo_mensual = sueldo_mensual;
}

void Empleado::asignar_llegadas_tarde(int llegadas_tarde){
	this->llegadas_tarde = llegadas_tarde;
}

void Empleado::asignar_ausencias(int ausencias){
	this->ausencias = ausencias;
}

float Empleado::liquidar_sueldo(){
	float sueldo;
	float suelto_por_dia = sueldo_mensual/30;
	if(ausencias == 0 && llegadas_tarde < 3){ 
		sueldo = sueldo_mensual + (0.10*sueldo_mensual);
	}
	if(ausencias > 0){
		sueldo = sueldo_mensual - suelto_por_dia*ausencias;
	} 
	return sueldo;
}

void Empleado::a_cadena(){
	cout << "----------------------" << endl;
	cout << "Legajo :" <<"  "<< legajo << endl;
	cout << "Nombre :"<<"  "<< nombre << endl;
	cout << "Tipo de trabajador:"<<" Empleado."<< endl;
	cout << "Sueldo mensual"<<"  "<< sueldo_mensual << endl;
	cout << "Llegadas tarde"<<"  "<< llegadas_tarde << endl;
	cout << "Ausencias"<<"  "<< ausencias << endl;
	cout << "Liquidación del sueldo:"<<"  "<< sueldo_a_cobrar << endl;
	cout << "----------------------" << endl;
}
