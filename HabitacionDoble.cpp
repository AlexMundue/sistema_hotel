#include "Habitacion.cpp"
class HabitacionDoble: public Habitacion{
	public:
		HabitacionDoble(int _ID);
		static int habitacionesDoblesRentadas;
		static void aumentarHabitacionesDoblesRentadas(){HabitacionDoble::habitacionesDoblesRentadas++;};
		static void disminuirHabitacionesDoblesRentadas(){HabitacionDoble::habitacionesDoblesRentadas--;};
		
};

int HabitacionDoble::habitacionesDoblesRentadas = 0;

HabitacionDoble::HabitacionDoble(int _ID): Habitacion(800, _ID, 2){
}


