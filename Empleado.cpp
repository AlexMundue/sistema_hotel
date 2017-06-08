#include "Persona.cpp"
#include <string.h>

using namespace std;

class Empleado: public Persona {
	char puesto[20];
	float sueldo;
	public: 
		Empleado(){};
		Empleado(int _sueldo, char* _puesto, char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID);
		virtual	int vender(int) = 0;
		void mostrar() const;	
		static int noEmpleados;
		static void agregarEmpleado(){Empleado::noEmpleados++;};	
};

int Empleado::noEmpleados = 0;

Empleado::Empleado(int _sueldo, char* _puesto, char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID): Persona(_nombre, _telefono, _direccion, _RFC, _ID){
	sueldo = _sueldo;
	strcpy(puesto,_puesto);
}
void Empleado::mostrar() const{
	Persona::mostrar();
	cout<<"Puesto: "<<puesto<<endl;
	cout<<"Sueldo: "<<sueldo<<endl;
}
