class Habitacion{
	bool estatus;
	float precio;
	int ID;
	int noPersonas;
	Persona* clienteHospedado;
	public:
		Habitacion(){};
		~Habitacion(){delete clienteHospedado;};
		Habitacion(float,int,int);
		static int noHabitacionesRentadas;
		static void aumentarHabitacionesRentadas();
		static void disminuirHabitacionesRentadas();
		void rentar(Persona*);
		void desocupar();
		bool disponible(){return estatus;};
		int getPrecio(){return precio;};
		friend int verNoPersonas(Habitacion* habitacion);
		void reportar(char*, ofstream&);
		virtual void reportar(ofstream&){};
};
