#include "Habitacion.cpp"
class HabitacionDeLujo: public Habitacion{
	public:
		HabitacionDeLujo(int _ID);
		static int habitacionesDeLujoRentadas;
		static void aumentarHabitacionesDeLujoRentadas(){HabitacionDeLujo::habitacionesDeLujoRentadas++;};
		static void disminuirHabitacionesDeLujoRentadas(){HabitacionDeLujo::habitacionesDeLujoRentadas--;};
		void reportar(ofstream&);
};

int HabitacionDeLujo::habitacionesDeLujoRentadas = 0;

HabitacionDeLujo::HabitacionDeLujo(int _ID): Habitacion(1500, _ID, 5){
}

void HabitacionDeLujo::reportar(ofstream& fescritura){
	Habitacion::reportar("Habitacion de lujo", fescritura);
}
