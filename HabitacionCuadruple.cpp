#include "Habitacion.cpp"
class HabitacionCuadruple: public Habitacion{
	public:
		HabitacionCuadruple(int _ID);
		static int habitacionesCuadruplesRentadas;
		static void aumentarHabitacionesCuadruplesRentadas(){HabitacionCuadruple::habitacionesCuadruplesRentadas++;};
		static void disminuirHabitacionesCuadruplesRentadas(){HabitacionCuadruple::habitacionesCuadruplesRentadas--;};
		void reportar(ofstream&);
};

int HabitacionCuadruple::habitacionesCuadruplesRentadas = 0;

HabitacionCuadruple::HabitacionCuadruple(int _ID): Habitacion(1100, _ID, 4){
}

void HabitacionCuadruple::reportar(ofstream& fescritura){
	Habitacion::reportar("Habitacion cuadruple", fescritura);
}
