#include <fstream>
#include <string.h>

using namespace std;

class Persona{
	string nombre;
	string telefono;
	string direccion;
	string RFC;
	int ID;
	public:
		Persona(){};
		~Persona(){};
		Persona(string _nombre, string _telefono, string _direccion, string _RFC, int _ID);
		virtual void mostrar() const;
		string getNombre(){return nombre;};
		string getTelefono(){return telefono;};
		string getDireccion(){return direccion;};
		string getRFC(){return RFC;};
		int getID(){return ID;};
		virtual void reportar(ofstream&){};
		virtual void reportar(){};
		virtual void vender(float){};
		virtual bool estaRentando(){};
		virtual void rentar(int){};
};


