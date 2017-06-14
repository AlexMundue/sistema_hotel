#include "Empleado.cpp"
class EmpleadoDeServicio: public Empleado{
	public: 
		static int noEmpleadosDeServicio;
		EmpleadoDeServicio(){};
		EmpleadoDeServicio(char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID);
		~EmpleadoDeServicio(){};
		static void aumentarEmpleadosDeServicio(){EmpleadoDeServicio::noEmpleadosDeServicio++;};
		static void disminuirEmpleadosDeServicio(){EmpleadoDeServicio::noEmpleadosDeServicio--;};
		void reportarPorTipo();
};

int EmpleadoDeServicio::noEmpleadosDeServicio = 0;

EmpleadoDeServicio::EmpleadoDeServicio(char _nombre[30], int _telefono, char _direccion[40], char _RFC[20], int _ID): Empleado(6000, "Empleado de servicio", _nombre, _telefono, _direccion, _RFC, _ID){
	
}

void EmpleadoDeServicio::reportarPorTipo(){
	ofstream fescritura("Reportes/Empleados/EmpleadosDeServicio.txt", ios::app);
	Empleado::reportarPorTipo(fescritura);
}
