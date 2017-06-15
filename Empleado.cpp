#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.cpp"
#include <string.h>
#include <fstream>

using namespace std;

class Empleado: public Persona {
	string puesto;
	float sueldo;
	public: 
		Empleado(){};
		~Empleado(){};
		Empleado(int _sueldo, string _puesto, string _nombre, string _telefono, string _direccion, string _RFC, int _ID);
		void mostrar() const;	
		static int noEmpleados;
		static void agregarEmpleado(){Empleado::noEmpleados++;};
		void reportar(ofstream&);	
		void aumentarSueldo(float);
};

int Empleado::noEmpleados = 0;

Empleado::Empleado(int _sueldo, string _puesto, string _nombre, string _telefono, string _direccion, string _RFC, int _ID): Persona(_nombre, _telefono, _direccion, _RFC, _ID){
	sueldo = _sueldo;
	puesto = _puesto;
}
void Empleado::mostrar() const{
	Persona::mostrar();
	cout<<"Puesto: "<<puesto<<endl;
	cout<<"Sueldo: "<<sueldo<<endl;
}

void Empleado::reportar(ofstream& fescritura){
	if(fescritura){
		fescritura<<puesto<<endl<<"Nombre: "<<getNombre()<<endl<<
		"Telefono: "<<getTelefono()<<endl<<
		"Dirección: "<<getDireccion()<<endl<<
		"RFC: "<<getRFC()<<endl<<
		"ID: "<<getID()<<endl<<
		"Sueldo: $"<<sueldo<<endl<<endl;
	} else{
		cout<<"Error";
	}
}

void Empleado::aumentarSueldo(float bonos){
	sueldo+=bonos;
}

#endif
