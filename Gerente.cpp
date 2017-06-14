#include "Empleado.cpp"
#include <fstream>
#include <string.h>
class Gerente: public Empleado{
	char *ubicacionReporte = "Reportes/Empleados/Gerentes.txt";
	public: 
		static int noGerentes;
		Gerente(){};
		~Gerente(){};
		Gerente(char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID);
		static void aumentarGerentes(){Gerente::noGerentes++;};
		static void disminuirGerentes(){Gerente::noGerentes--;};
		void reportar();
};

int Gerente::noGerentes = 0;


Gerente::Gerente(char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID): Empleado(25000, "Gerente", _nombre, _telefono, _direccion, _RFC, _ID){
	
}

void Gerente::reportar(){
	ofstream fescritura(ubicacionReporte, ios::app);
	Empleado::reportar(fescritura);
	fescritura.close();
}

