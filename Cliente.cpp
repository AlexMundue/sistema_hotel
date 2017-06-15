#include "Persona.cpp"
#include <fstream>
#include <string.h>
using namespace std;

class Cliente: public Persona {
	const char *ubicacionReporte = "Reportes/Clientes.txt";
	string	email;
	bool	rentando;
	int noHabitacion;
	public: 
		Cliente(string email, string _nombre, string _telefono, string _direccion, string _RFC, int _ID);
		~Cliente(){};
		void rentar(int);
		static int noClientes;
		static void aumentarClientes(){Cliente::noClientes++;};
		static void disminuirClientes(){Cliente::noClientes--;};
		void desocupar();
		void reportar();
		bool estaRentando(){return rentando;};
};

int Cliente::noClientes = 0;

Cliente::Cliente(string _email, string _nombre, string _telefono, string _direccion, string _RFC, int _ID): Persona(_nombre, _telefono, _direccion, _RFC, _ID){
	email = _email;
	noHabitacion = NULL;
	rentando = false;
}

void Cliente::rentar(int numero){
	rentando = true;
	noHabitacion = numero;
}

void Cliente::desocupar(){
	rentando = false;
	noHabitacion = NULL;
}

void Cliente::reportar(){
	ofstream fescritura(ubicacionReporte, ios::app);
	if(fescritura){
		fescritura<<"Nombre: "<<getNombre()<<endl<<
		"Telefono: "<<getTelefono()<<endl<<
		"Dirección: "<<getDireccion()<<endl<<
		"RFC: "<<getRFC()<<endl<<
		"ID: "<<getID()<<endl;
		if(noHabitacion != NULL){
			fescritura<<"Número de habitación: "<<noHabitacion<<endl;
		}
		fescritura<<endl;
	} else{
		cout<<"error "<<ubicacionReporte;
	}
}

