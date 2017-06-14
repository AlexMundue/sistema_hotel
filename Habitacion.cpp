#ifndef HABITACION_H
#define HABITACION_H
#include "Habitacion.h"
#include <string.h>
using namespace std;

int Habitacion::noHabitacionesRentadas = 0;

Habitacion::Habitacion(float _precio, int _ID, int _noPersonas){
	estatus = true;
	precio = _precio;
	ID = _ID;
	noPersonas = _noPersonas;
}

void Habitacion::rentar(Persona* cliente){
	clienteHospedado = cliente;
	estatus = false;
}


void Habitacion::desocupar(){
	delete clienteHospedado;
	estatus = true;
}

void Habitacion::aumentarHabitacionesRentadas(){
	Habitacion::noHabitacionesRentadas++;
}

void Habitacion::disminuirHabitacionesRentadas(){
	Habitacion::noHabitacionesRentadas--;
}

void Habitacion::reportar(char tipoHabitacion[], ofstream& fescritura){
	if(fescritura){
		fescritura<<tipoHabitacion<<endl<<
		"ID: "<<ID<<endl<<
		"Estatus: "<<estatus<<endl<<
		"Precio: "<<precio<<endl<<
		"Número de personas: "<<noPersonas<<endl<<endl;
	} else{
		cout<<"Error Habitaciones.txt";
	}
}

#endif
