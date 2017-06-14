#include "Empleado.cpp"
class Administrador: public Empleado{
	float bonos;
	public: 
		static int noAdministradores;
		Administrador(){};
		~Administrador(){};
		Administrador(char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID);
		static void aumentarAdministradores(){Administrador::noAdministradores++;};
		static void disminuirAdministradores(){Administrador::noAdministradores--;};
		void reportarPorTipo();
		void vender(float);
};

int Administrador::noAdministradores = 0;

Administrador::Administrador(char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID): Empleado(8000, "Administrador", _nombre, _telefono, _direccion, _RFC, _ID){
	
}

void Administrador::vender(float comision){
	bonos+=comision;
	Empleado::aumentarSueldo(comision);
}

void Administrador::reportarPorTipo(){
	ofstream fescritura("Reportes/Empleados/Administradores.txt", ios::app);
	Empleado::reportarPorTipo(fescritura);
}
