class Persona{
	char nombre[30];
	char telefono[20];
	char direccion[40];
	char RFC[20];
	int ID;
	public:
		Persona(){};
		~Persona(){};
		Persona(char _nombre[30], char _telefono[20], char _direccion[40], char _RFC[20], int _ID);
		virtual void mostrar() const;
		char* getNombre(){return nombre;};
		char* getTelefono(){return telefono;};
		char* getDireccion(){return direccion;};
		char* getRFC(){return RFC;};
		int getID(){return ID;};
		virtual void reportar(){};
		virtual void reportarPorTipo(){};
		virtual void vender(float){};
		virtual bool estaRentando(){};
		virtual void rentar(int){};
};


