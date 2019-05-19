#include <iostream>
#include "consultor.h"

Consultor::Consultor(int legajo,string nombre):Trabajador(legajo,nombre){
	valor_hora_catedra = 0;
	cantidad_horas_catedra = 0;
	horas_a_descontar = 0;
}

void Consultor::asignar_sueldo_hora_catedra(float valor_hora_catedra){
	this->valor_hora_catedra = valor_hora_catedra;
}

void Consultor::asignar_cantidad_horas_catedra(int cantidad_horas_catedra){
	this->cantidad_horas_catedra = cantidad_horas_catedra;
}

void Consultor::asignar_horas_a_descontar(int horas_a_descontar){
	this->horas_a_descontar = horas_a_descontar;
}

float Consultor::liquidar_sueldo(){
	float sueldo =  valor_hora_catedra * cantidad_horas_catedra * 4;
	if(horas_a_descontar > 0){
		sueldo -= sueldo/(cantidad_horas_catedra*4) * horas_a_descontar;
	}
	return sueldo;
}

void Consultor::a_cadena(){
	cout << "----------------------" << endl;
	cout << "Legajo:" <<"  "<<legajo << endl;
	cout << "Nombre:" <<"  "<<nombre << endl;
	cout << "Tipo de Trabajador:" <<"Consultor. "<< endl;
	cout << "Valor hora catedra:" <<"  "<<valor_hora_catedra<< endl;
	cout << "Cantidad horas catedra:" <<"  "<<cantidad_horas_catedra << endl;
	cout << "Horas a descontar:" <<"  "<<horas_a_descontar << endl;
	cout << "Liquidación sueldo:" <<"  "<<sueldo_a_cobrar << endl;
	cout << "----------------------" << endl;
}

