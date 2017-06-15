#include "Empleado.cpp"
#include <fstream>
#include <string.h>
using namespace std;

class Administrador: public Empleado{
	float bonos;
	const char *ubicacionReporte = "Reportes/Empleados/Administradores.txt";
	public: 
		static int noAdministradores;
		Administrador(){};
		~Administrador(){};
		Administrador(string _nombre, string _telefono, string _direccion, string _RFC, int _ID);
		static void aumentarAdministradores(){Administrador::noAdministradores++;};
		static void disminuirAdministradores(){Administrador::noAdministradores--;};
		void reportar();
		void vender(float);
};

int Administrador::noAdministradores = 0;

Administrador::Administrador(string _nombre, string _telefono, string _direccion, string _RFC, int _ID): Empleado(8000, "Administrador", _nombre, _telefono, _direccion, _RFC, _ID){
	
}

void Administrador::vender(float comision){
	bonos+=comision;
	Empleado::aumentarSueldo(comision);
}


void Administrador::reportar(){
	ofstream fescritura(ubicacionReporte, ios::app);
	Empleado::reportar(fescritura);
	fescritura.close();
}

