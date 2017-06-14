#include "Habitacion.cpp"
class HabitacionCuadruple: public Habitacion{
	public:
		HabitacionCuadruple(int _ID);
		static int habitacionesCuadruplesRentadas;
		static void aumentarHabitacionesCuadruplesRentadas(){HabitacionCuadruple::habitacionesCuadruplesRentadas++;};
		static void disminuirHabitacionesCuadruplesRentadas(){HabitacionCuadruple::habitacionesCuadruplesRentadas--;};
	
};

int HabitacionCuadruple::habitacionesCuadruplesRentadas = 0;

HabitacionCuadruple::HabitacionCuadruple(int _ID): Habitacion(1100, _ID, 4){
}

