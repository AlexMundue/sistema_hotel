#ifndef PERSONA_H
#define PERSONA_H
#include "Persona.h"
#include <string.h>
using namespace std;

Persona::Persona(string _nombre, string _telefono, string _direccion, string _RFC, int _ID){
	nombre = _nombre;
	telefono = _telefono;
	direccion = _direccion;
	RFC = _RFC;
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
