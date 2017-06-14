#include "Persona.cpp"
#include <fstream>
class Cliente: public Persona {
	char	email[40];
	bool	rentando;
	int noHabitacion;
	public: 
		Cliente(char email[], char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID);
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

Cliente::Cliente(char _email[], char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID): Persona(_nombre, _telefono, _direccion, _RFC, _ID){
	strcpy(email, _email);
	noHabitacion = -1;
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
	ofstream fescritura("Reportes/Clientes.txt", ios::app);
	if(fescritura){
		fescritura<<"Nombre: "<<getNombre()<<endl<<
		"Telefono: "<<getTelefono()<<endl<<
		"Dirección: "<<getDireccion()<<endl<<
		"RFC: "<<getRFC()<<endl<<
		"ID: "<<getID()<<endl<<endl;
	} else{
		cout<<"error Clientes.txt";
	}
}
