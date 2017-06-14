#include "Empleado.cpp"
class Gerente: public Empleado{
	public: 
		static int noGerentes;
		Gerente(){};
		~Gerente(){};
		Gerente(char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID);
		static void aumentarGerentes(){Gerente::noGerentes++;};
		static void disminuirGerentes(){Gerente::noGerentes--;};
		void reportarPorTipo();
};

int Gerente::noGerentes = 0;

Gerente::Gerente(char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID): Empleado(25000, "Gerente", _nombre, _telefono, _direccion, _RFC, _ID){
	
}

void Gerente::reportarPorTipo(){
	ofstream fescritura("Reportes/Empleados/Gerentes.txt", ios::app);
	Empleado::reportarPorTipo(fescritura);
}


