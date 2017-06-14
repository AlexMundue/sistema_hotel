#include "Habitacion.cpp"
class HabitacionDeLujo: public Habitacion{
	public:
		HabitacionDeLujo(int _ID);
		static int habitacionesDeLujoRentadas;
		static void aumentarHabitacionesDeLujoRentadas(){HabitacionDeLujo::habitacionesDeLujoRentadas++;};
		static void disminuirHabitacionesDeLujoRentadas(){HabitacionDeLujo::habitacionesDeLujoRentadas--;};
		
};

int HabitacionDeLujo::habitacionesDeLujoRentadas = 0;

HabitacionDeLujo::HabitacionDeLujo(int _ID): Habitacion(1500, _ID, 5){
}


