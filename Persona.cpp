#ifndef PERSONA_H
#define PERSONA_H
#include "Persona.h"
#include <string.h>
using namespace std;

Persona::Persona(char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID){
	strcpy(nombre,_nombre);
	telefono = _telefono;
	strcpy(direccion,_direccion);
	strcpy(RFC,_RFC);
	ID = _ID;
}

void Persona::mostrar() const{
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Telefono: "<<telefono<<endl;
	cout<<"Direccion: "<<direccion<<endl;
	cout<<"RFC: "<<RFC<<endl;
	cout<<"ID: "<<ID<<endl;
}

#endif
