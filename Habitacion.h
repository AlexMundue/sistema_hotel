
class Habitacion{
	bool estatus;
	float precio;
	int ID;
	int noPersonas;
	Persona* clienteHospedado;
	public:
		static int habitacionesDisponibles;
		void aumentarContador(Habitacion::habitacionesDisponibles++;);
		void disminuir(){Habitacion::habitacionesDisponibles--;};

};


