#include "Empleado.cpp"
class Gerente: public Empleado{
	public: 
		static int noGerentes;
		Gerente(){};
		~Gerente(){};
		Gerente(char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID);
		static void aumentarGerentes(){Gerente::noGerentes++;};
		static void disminuirGerentes(){Gerente::noGerentes--;};
		void reportarPorTipo();
};

int Gerente::noGerentes = 0;

Gerente::Gerente(char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID): Empleado(25000, "Gerente", _nombre, _telefono, _direccion, _RFC, _ID){
	
}

void Gerente::reportarPorTipo(){
	ofstream fescritura("Reportes/Empleados/Gerentes.txt", ios::app);
	Empleado::reportarPorTipo(fescritura);
}
