#include "Persona.cpp"
class Cliente: public Persona {
	char	email[40];
	bool	rentando;
	int noHabitacion;
	public: 
		Cliente(char email[40], char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID);
		void rentar(int numero);
		static int numeroClientes;
		static void aumentarClientes(){Cliente::numeroClientes++;};
		static void disminuirClientes(){Cliente::numeroClientes--;};
};

int Cliente::numeroClientes = 0;

Cliente::Cliente(char _email[40], char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID): Persona(_nombre, _telefono, _direccion, _RFC, _ID){
	strcpy(email, _email);
	noHabitacion = NULL;
	rentando = false;
}

void Cliente::rentar(int numero){
	rentando = true;
	noHabitacion = numero;
}
