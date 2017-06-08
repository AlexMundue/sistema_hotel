#include "Empleado.cpp"
class Gerente: public Empleado{
	float bonos;
	public: 
		static int noGerentes;
		Gerente(){};
		Gerente(char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID);
		static void aumentarGerentes(){Gerente::noGerentes++;};
		static void disminuirGerentes(){Gerente::noGerentes--;};
};

int Gerente::noGerentes = 0;

Gerente::Gerente(char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID): Empleado(25000, "Gerente", _nombre, _telefono, _direccion, _RFC, _ID){
	
}

