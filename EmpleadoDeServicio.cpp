#include "Empleado.cpp"
#include <fstream>
class EmpleadoDeServicio: public Empleado{
	const char *ubicacionReporte = "Reportes/Empleados/EmpleadosDeServicio.txt";
	public: 
		static int noEmpleadosDeServicio;
		EmpleadoDeServicio(){};
		EmpleadoDeServicio(char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID);
		~EmpleadoDeServicio(){};
		static void aumentarEmpleadosDeServicio(){EmpleadoDeServicio::noEmpleadosDeServicio++;};
		static void disminuirEmpleadosDeServicio(){EmpleadoDeServicio::noEmpleadosDeServicio--;};
		void reportar();
};

int EmpleadoDeServicio::noEmpleadosDeServicio = 0;

EmpleadoDeServicio::EmpleadoDeServicio(char _nombre[], char _telefono[], char _direccion[], char _RFC[], int _ID): Empleado(6000, "Empleado de servicio", _nombre, _telefono, _direccion, _RFC, _ID){
	
}

void EmpleadoDeServicio::reportar(){
	ofstream fescritura(ubicacionReporte, ios::app);
	Empleado::reportar(fescritura);
	fescritura.close();
}


