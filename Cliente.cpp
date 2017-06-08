#include "Persona.cpp"
#include <fstream>
class Cliente: public Persona {
	char	email[40];
	bool	rentando;
	int noHabitacion;
	public: 
		Cliente(char email[40], char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID);
		void rentar(int numero);
		static int noClientes;
		static void aumentarClientes(){Cliente::noClientes++;};
		static void disminuirClientes(){Cliente::noClientes--;};
		void rentar();
		void desocupar();
		void reportar();
};

int Cliente::noClientes = 0;

Cliente::Cliente(char _email[40], char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID): Persona(_nombre, _telefono, _direccion, _RFC, _ID){
	strcpy(email, _email);
	noHabitacion = -1;
	rentando = false;
}

void Cliente::rentar(int numero){
	rentando = true;
	noHabitacion = numero;
}

void Cliente::rentar(){
	rentando = true;
}

void Cliente::desocupar(){
	rentando = false;
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
