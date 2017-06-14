#include <iostream>
#include "Cliente.cpp"
#include "Gerente.cpp"
#include "Administrador.cpp"
#include "EmpleadoDeServicio.cpp"
#include "HabitacionDoble.cpp"
#include "HabitacionCuadruple.cpp"
#include "HabitacionDeLujo.cpp"
#include <string.h>
#include <typeinfo>

using namespace std;

int main(){
	remove("Reportes/Empleados/Empleados.txt");
	remove("Reportes/Empleados/Gerentes.txt");
	remove("Reportes/Empleados/Administradores.txt");
	remove("Reportes/Empleados/EmpleadosDeServicio.txt");
	remove("Reportes/Clientes.txt");
	
	//codigo = codigo de empleado
	int opcion = 0, codigo = 0;
	int maxAdministradores = 3;
	int maxEmpleadosDeServicio = 5;
	int maxGerentes = 2; 
	int maxEmpleados = 10;
	int maxClientes = 10;
	//Se inician en NULL los arreglos para saber que están vacíos
	Persona* empleados[maxEmpleados];
	for(int i = 0; i < maxEmpleados; i++){
		empleados[i] = NULL;
	}
	ofstream fescritura("Reportes/Empleados/Empleados.txt", ios::app);
	empleados[0] = new Gerente("Oscar Ramirez", "3326567894","Federalismo 433", "MEJD9898JCC",0);
	Empleado::agregarEmpleado();
	Gerente::aumentarGerentes();
	empleados[0]->reportar();
	empleados[0]->reportar(fescritura);
	empleados[1] = new Administrador("Carlos Salas", "3379854613","Juan de la barranca 847", "JDJD7895LNN",1);
	Empleado::agregarEmpleado();
	Administrador::aumentarAdministradores();
	empleados[1]->reportar();
	empleados[1]->reportar(fescritura);
	empleados[2] = new EmpleadoDeServicio("Juan Antonio Salamanca", "3311875244","Juarez 222", "AHKJ1717JXX",2);
	Empleado::agregarEmpleado();
	EmpleadoDeServicio::aumentarEmpleadosDeServicio();
	empleados[2]->reportar();
	empleados[2]->reportar(fescritura);
	fescritura.close();
	Persona* clientes[maxClientes];
	for(int i = 0; i < maxClientes; i++){
		clientes[i] = NULL;
	}
	//Habitaciones
	int noHabitaciones = 10;
	Habitacion* habitaciones[noHabitaciones];
	habitaciones[0] = new HabitacionDoble(0);
	habitaciones[1] = new HabitacionDoble(1);
	habitaciones[2] = new HabitacionDoble(2);
	habitaciones[3] = new HabitacionDoble(3);
	habitaciones[4] = new HabitacionDoble(4);
	habitaciones[5] = new HabitacionCuadruple(5);
	habitaciones[6] = new HabitacionCuadruple(6);
	habitaciones[7] = new HabitacionCuadruple(7);
	habitaciones[8] = new HabitacionDeLujo(8);
	habitaciones[9] = new HabitacionDeLujo(9);
	int precioHabitacionDoble = habitaciones[0]->getPrecio();
	int precioHabitacionCuadruple = habitaciones[5]->getPrecio();
	int precioHabitacionDeLujo = habitaciones[8]->getPrecio();
	int noHabitacionesDobles = 5;
	int noHabitacionesCuadruples = 3;
	int noHabitacionesDeLujo = 2;
	remove("Reportes/Habitaciones/Habitaciones.txt");
	remove("Reportes/Habitaciones/HabitacionesDisponibles.txt");
	fescritura.open("Reportes/Habitaciones/Habitaciones.txt", ios::app);
	ofstream fescritura2("Reportes/Habitaciones/HabitacionesDisponibles.txt", ios::app);
	for(int i = 0; i < noHabitaciones; i++){
		habitaciones[i]->reportar(fescritura);
		habitaciones[i]->reportar(fescritura2);
	}
	fescritura.close();
	fescritura2.close();
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int verNoPersonas(Habitacion*);
	
	do{
		cout<<"Elige una opcion: "<<endl;
		cout<<"1. Empleados"<<endl<<"2. Clientes"<<endl<<"3. Habitacion"<<endl<<"4. Renta de habitacion"<<endl<<"5. Reportes"<<endl<<"6. Salir"<<endl;
		cin>>opcion;
		system("cls");
		switch(opcion){
			case 1:
				cout<<"1. Ingresar un nuevo registro."<<endl<<"2. Consultar uno o varios registros."<<endl<<"3. Eliminar un registro."<<endl;
				cin>>opcion;
				system("cls");
				switch(opcion){
					case 1:
						{
							//Se revisa si ya se llego al límete de empleados
							if(maxEmpleados > Empleado::noEmpleados){

								char nombre[30];
								char telefono[20];
								char direccion[40];
								char RFC[20];
								int ID;
								cout<<"1. Gerente."<<endl<<"2. Administrador."<<endl<<"3. Servicio."<<endl;
								cin>>opcion;
								//Se obtienene los datos del nuevo empleado
								cout<<"Nombre: ";
								cin>>nombre;
								cout<<"Telefono: ";
								cin>>telefono;
								cout<<"Direccion: ";
								cin>>direccion;
								cout<<"RFC: ";
								cin>>RFC;
								
								//En dado caso que IDS de registros de empleados anteriores se hayan dado de baja y estén disponibles para su uso, los volvemos a reusar 
								//para no tener memoria desperdiciada y también para saber su posición en el arreglo
								for(int i = 0; i < maxEmpleados; i++){
									if(empleados[i] == NULL){
										ID = i;
										break;
									}
								}
								
								//Para agregar un Gerente
								if(opcion == 1 && maxGerentes > Gerente::noGerentes){
									empleados[ID] = new Gerente(nombre,telefono,direccion,RFC,ID);
									Gerente::aumentarGerentes();
								}
								//Para agregar un Administrador
								else if(opcion == 2 && maxAdministradores > Administrador::noAdministradores){
									empleados[ID] = new Administrador(nombre,telefono,direccion,RFC,ID);
									Administrador::aumentarAdministradores();
								}
								//Para agregar un empleado de servicio
								else if(opcion == 3 && maxEmpleadosDeServicio > EmpleadoDeServicio::noEmpleadosDeServicio){
									empleados[ID] = new EmpleadoDeServicio(nombre,telefono,direccion,RFC,ID);
									EmpleadoDeServicio::aumentarEmpleadosDeServicio();
								}
								
								fescritura.open("Reportes/Empleados/Empleados.txt", ios::app);
								empleados[ID]->reportar();
								empleados[ID]->reportar(fescritura);
								fescritura.close();
								Empleado::agregarEmpleado();
								cout<<"Se a creado satisfactoriamente el nuevo registro."<<endl<<"ID: "<<ID<<endl;
								
								//En dado caso que ya esté el límite de empleados de un tipo, se informa el número actual
								if(opcion == 1 && Gerente::noGerentes >= maxGerentes) {
									cout<<"-Numero maximo de gerentes: "<<maxGerentes<<"\tActualmente: "<<Gerente::noGerentes<<endl;
								}else if(opcion == 2 && Administrador::noAdministradores >= maxAdministradores) {
									cout<<"-Numero maximo de Administradores: "<<maxAdministradores<<"\tActualmente: "<<Administrador::noAdministradores<<endl;
								}else if(opcion == 3 && EmpleadoDeServicio::noEmpleadosDeServicio >= maxEmpleadosDeServicio) {
									cout<<"-Numero maximo de empleados de servicio: "<<maxEmpleadosDeServicio<<"\tActualmente: "<<EmpleadoDeServicio::noEmpleadosDeServicio<<endl;
								}
								
							}else {
								//Este caso es en dado caso que alguna de las condiciones de limite de empleado se presente
									cout<<"-Numero maximo de empleados: "<<maxEmpleados<<"\tActualmente: "<<Gerente::noEmpleados<<endl;
							}
						}
						system("PAUSE");
						system("cls");
					break;
					
					case 2:
						{
						int id = 0;
						do{
							cout<<"1. Consultar registro."<<endl<<"2. SALIR."<<endl;
							cin>>opcion;
							system("cls");
							if(opcion == 1){
								cout<<"ID del empleado a buscar: ";
								cin>>id;
								if(empleados[id] != NULL){
									empleados[id]->mostrar();
								}else{
									cout<<"No se encontro un empleado con ese ID"<<endl;
								}
							}
							system("PAUSE");
							system("cls");
						}while(opcion!=2);
						}
					break;
					
					case 3:
						{
							if(Empleado::noEmpleados != 0){
								int id = 0;
								cout<<"Ingresa el codigo del registro a eliminar: ";
								cin>>id;
								int tipo;
								if(empleados[id] != NULL){
									//Se compara que tipo de empleado se eliminó, para así disminuir el contador de ese tipo de empleado y así continuar teniendo el conteo
									if(typeid(Gerente) == typeid(*(empleados[id]))){
										Gerente::disminuirGerentes();
										cout<<"Gerentes: "<<Gerente::noGerentes;
										remove("Reportes/Empleados/Gerentes.txt");
										tipo = 0;
									}
									else if(typeid(Administrador) == typeid(*(empleados[id]))){
										Administrador::disminuirAdministradores();
										cout<<"Administradores: "<<Administrador::noAdministradores;
										remove("Reportes/Empleados/Administradores.txt");
										tipo = 1;
									}
									else if(typeid(EmpleadoDeServicio) == typeid(*(empleados[id]))){
										EmpleadoDeServicio::disminuirEmpleadosDeServicio();
										cout<<"EmpleadoDeServicio: "<<EmpleadoDeServicio::noEmpleadosDeServicio;
										remove("Reportes/Empleados/EmpleadosDeServicio.txt");
										tipo = 2;
									}
								
									delete empleados[id];
									empleados[id] = NULL;
									//Se actualiza la lista de los empleados en general y por tipo
									fescritura.open("Reportes/Empleados/Empleados.txt");
									for(int i = 0; i < maxEmpleados; i++){
										if(empleados[i]!=NULL){
											empleados[i]->reportar(fescritura);
											if(typeid(Gerente) == typeid(*(empleados[i])) && tipo == 0){	
												empleados[i]->reportar();
											}	
											else if(typeid(Administrador) == typeid(*(empleados[i])) && tipo == 1){
												empleados[i]->reportar();
											}
											else if(typeid(EmpleadoDeServicio) == typeid(*(empleados[i])) && tipo == 2){
												empleados[i]->reportar();
											}
										}
									}
									fescritura.close();
									cout<<"\nEl registro se ha eliminado correctamente."<<endl;
								}else {
									cout<<"El ID ingresado no está registrado a un empleado."<<endl;
								}
								system("PAUSE");
								system("cls");			
							}else {
								cout<<"No se tienen registros de empleados."<<endl;
							}
						}
					break;			
				}
			break;
			
			case 2:
				cout<<"1. Ingresar un nuevo registro."<<endl<<"2. Consultar uno o varios registros."<<endl<<"3. Eliminar un registro."<<endl;
				cin>>opcion;
				system("cls");
				switch(opcion){
					case 1:
					{
						if(maxClientes > Cliente::noClientes){
							char email[40];
							char nombre[30];
							char telefono[20];
							char direccion[40];
							char RFC[20];
							int ID;
							cout<<"Nombre: ";
							cin>>nombre;
							cout<<"Telefono: ";
							cin>>telefono;
							cout<<"Direccion: ";
							cin>>direccion;
							cout<<"RFC: ";
							cin>>RFC;
							cout<<"Email: ";
							cin>>email;
							for(int i = 0; i < maxClientes; i++){
									if(clientes[i] == NULL){
										ID = i;
										break;
									}
								}
							clientes[ID] = new Cliente(email, nombre, telefono, direccion, RFC, ID);
							clientes[ID]->reportar();
							Cliente::aumentarClientes();
							cout<<"Se a creado satisfactoriamente el nuevo registro."<<endl<<"ID: "<<ID<<endl;
						}
						system("PAUSE");
						system("cls");
					}
					break;
					
					case 2:
					{
						int id = 0;
						do{
							cout<<"1. Consultar registro."<<endl<<"2. SALIR."<<endl;
							cin>>opcion;
							system("cls");
							if(opcion == 1){
								cout<<"ID del cliente a buscar: ";
								cin>>id;
								if(clientes[id] != NULL){
									clientes[id]->mostrar();
								}else{
									cout<<"No se encontro un cliente con ese ID"<<endl;
								}
							}
							system("PAUSE");
							system("cls");
						}while(opcion!=2);
					}
					break;
					
					case 3:
					{
						if(Cliente::noClientes != 0){
							int id;
							cout<<"Dime el codigo del registro a eliminar: ";
							cin>>id;
							if(clientes[id] != NULL){
								delete clientes[id];
								clientes[id] = NULL;
								fescritura.open("Reportes/Clientes.txt");
								for(int i = 0; i < maxClientes; i++){
									if(clientes[i]!=NULL){
										clientes[i]->reportar(fescritura);
									}
								}
								fescritura.close();
								cout<<"El registro se ha eliminado correctamente."<<endl;
								Cliente::disminuirClientes();
							}
						}else {
							cout<<"No hay registro de algun cliente."<<endl;
						}
						system("PAUSE");
						system("cls");
					}
					break;
				}
			break;
			
			case 3:
				//Para poder cambiar el estatus de una habitación 
				//Los gerentes son los únicos que pueden modificar el estatus
				cout<<"Ingresa codigo de empleado: "<<endl;
				cin>>codigo;
				if(empleados[codigo] != NULL){
					if(typeid(*(empleados[codigo])) == typeid(Gerente)){
						int noHabitacion;
						cout<<"Ingrese el ID de la habitacion a desocupar: ";
						cin>>noHabitacion;
						if(habitaciones[noHabitacion]->disponible() != true){
							habitaciones[noHabitacion]->desocupar();
							cout<<"Habitacion desocupada satisfactoriamente."<<endl;
							Habitacion::disminuirHabitacionesRentadas();
							if(verNoPersonas(habitaciones[noHabitacion]) == 2){
								HabitacionDoble::disminuirHabitacionesDoblesRentadas();
							}
							else if(verNoPersonas(habitaciones[noHabitacion]) == 4){
								HabitacionCuadruple::disminuirHabitacionesCuadruplesRentadas();
							}
							else if(verNoPersonas(habitaciones[noHabitacion]) == 5){
								HabitacionDeLujo::disminuirHabitacionesDeLujoRentadas();
							}
							fescritura.open("Reportes/Habitaciones/HabitacionesDisponibles.txt");
							fescritura2.open("Reportes/Habitaciones/HabitacionesNoDisponibles.txt");
							for(int i = 0; i < noHabitaciones; i++){
								if(habitaciones[i]->disponible() == true){
									habitaciones[i]->reportar(fescritura);
								}else{
									habitaciones[i]->reportar(fescritura2);
								}
							}
							fescritura.close();
							fescritura2.close();
						}else{
							cout<<"La habitacion esta desocupada."<<endl;
						}
					}else{
						cout<<"Solo los gerentes pueden hacer modificaciones a las habitaciones."<<endl;
					}
				}else{
					cout<<"El ID ingresado no existe."<<endl;
				}
				system("pause");
				system("cls");
			break;
			
			case 4:
				cout<<"Ingresa codigo de empleado: "<<endl;
				cin>>codigo;
				//Checamos que el empleado exista y que existen habitaciones disponibles
				if(empleados[codigo] != NULL && Habitacion::noHabitacionesRentadas < noHabitaciones && (Gerente::noGerentes > 0 || Administrador::noAdministradores > 0)){
					if(typeid(*(empleados[codigo])) == typeid(Gerente) || typeid(*(empleados[codigo])) == typeid(Administrador)){
						//Poner precios de las habitaciones
						cout<<"1) Habitacion Doble: $"<<precioHabitacionDoble<<endl;
						cout<<"2) Habitacion Cuadruple: $"<<precioHabitacionCuadruple<<endl;
						cout<<"3) Habitacion de Lujo: $"<<precioHabitacionDeLujo<<endl;	
						cin>>opcion;
						int ID;
						cout<<"Ingrese el ID del cliente que rentara la habitacion: ";
						cin>>ID;
						bool ventaHecha = false;
						int noHabitacion = 0;
						//Ciclo para encontrar habitación disponible
						for(int i = 0; i < noHabitaciones; i++){
							if(opcion == 1){
								if(verNoPersonas(habitaciones[i]) == 2 && habitaciones[i]->disponible() == true){
									noHabitacion = i;
									ventaHecha = true;
									HabitacionDoble::aumentarHabitacionesDoblesRentadas();
									break;
								}
							}else if(opcion == 2){
								if(verNoPersonas(habitaciones[i]) == 4 && habitaciones[i]->disponible() == true){
									noHabitacion = i;
									ventaHecha = true;
									HabitacionCuadruple::aumentarHabitacionesCuadruplesRentadas();
									break;
								}
							}else if(opcion == 3){
								if(verNoPersonas(habitaciones[i]) == 5 && habitaciones[i]->disponible() == true){
									noHabitacion = i;
									ventaHecha = true;
									HabitacionDeLujo::aumentarHabitacionesDeLujoRentadas();
									break;
								}
							}
						}
						
						if(ventaHecha == true && clientes[ID] != NULL && clientes[ID]->estaRentando() != true){
							//Si se encontró una habitación disponible entonces se procede a rentarla y saber quien la vendió
							int dias;
							cout<<"Dias que el cliente se va a hospedar: ";
							cin>>dias;
							habitaciones[noHabitacion]->rentar(clientes[ID]);
							Habitacion::aumentarHabitacionesRentadas();
							cout<<"Total: "<<habitaciones[noHabitacion]->getPrecio() * dias<<endl;
							cout<<"Venta realizada correctamente."<<endl<<endl;
							clientes[ID]->rentar(noHabitacion);
							//Si fue un administrador se cobra la comisión
							if(typeid(*(empleados[codigo])) == typeid(Administrador)){
								float comision = 0;
								comision = habitaciones[noHabitacion]->getPrecio() * .05 * dias;
								(*(empleados[codigo])).vender(comision);
								remove("Reportes/Empleados/Administradores.txt");
								remove("Reportes/Empleados/Gerentes.txt");
								remove("Reportes/Empleados/EmpleadosDeServicio.txt");
								fescritura2.open("Reportes/Empleados/Empleados.txt");
								for(int i = 0; i < maxEmpleados; i++){
									if(empleados[i] != NULL){
										empleados[i]->reportar();
										fescritura.close();
										empleados[i]->reportar(fescritura2);
									}
								}
								fescritura2.close();
							}
							fescritura.open("Reportes/Habitaciones/HabitacionesDisponibles.txt");
							fescritura2.open("Reportes/Habitaciones/HabitacionesNoDisponibles.txt");
							for(int i = 0; i < noHabitaciones; i++){
								if(habitaciones[i]->disponible() == true){
									habitaciones[i]->reportar(fescritura);
								}else{
									habitaciones[i]->reportar(fescritura2);
								}
							}
							fescritura.close();
							fescritura2.close();
						}else{
							cout<<"Error en habitaciones disponibles o al ingresar el ID del cliente o podria ser causado porque el cliente ya esta rentando actualmente(Maximo una renta por cliente)."<<endl;
						}
						
						//En dado caso que no se pueda rentar alguna se da a conocer la causa
						if(opcion == 1 && HabitacionDoble::habitacionesDoblesRentadas >= noHabitacionesDobles){
							cout<<"Habitaciones Dobles AGOTADAS"<<endl;
						}
						else if(opcion == 2 && HabitacionCuadruple::habitacionesCuadruplesRentadas >= noHabitacionesCuadruples){
							cout<<"Habitaciones Cuadruples AGOTADAS"<<endl;
						}	
						else if(opcion == 3 && HabitacionDeLujo::habitacionesDeLujoRentadas >= noHabitacionesDeLujo){
							cout<<"Habitaciones de Lujo AGOTADAS"<<endl;
						}	
					}else{
					cout<<"Permisos insuficientes."<<endl;
					}
				}else{
					cout<<"Ese ID no existe o  no hay suficientes empleados con los permisos necesarios."<<endl;
				}
				system("pause");
				system("cls");
			break;
			
			case 5:
				int opcion2;
				cout<<"1. Lista de Clientes"<<endl<<"2. Lista de Habitaciones totales"<<endl<<"3. Reporte de Habitaciones disponibles"<<endl<<"4. Reporte de Habitaciones NO disponibles."<<endl
				<<"5. Lista de Empleados"<<endl<<"6. Lista de Empleados de acuerdo a tipos."<<endl;
				cin>>opcion2;
				ifstream flectura;
				switch(opcion2){
					case 1:
						{
							flectura.open("Reportes/Clientes.txt");
						}
					break;
					
					case 2:
						{
							flectura.open("Reportes/Habitaciones/Habitaciones.txt");
						}
					break;
					
					
					case 3:
						{
							flectura.open("Reportes/Habitaciones/HabitacionesDisponibles.txt");
						}
					break;
					
					
					case 4:
						{
							flectura.open("Reportes/Habitaciones/HabitacionesNoDisponibles.txt");
						}
					break;
					
					
					case 5:
						{
							flectura.open("Reportes/Empleados/Empleados.txt");
						}
					break;
					
					
					case 6:
						{
							char car;
							flectura.open("Reportes/Empleados/Gerentes.txt");
							while(flectura.get(car)){
							cout<<car;
							}
							flectura.close();
							flectura.open("Reportes/Empleados/Administradores.txt");
							while(flectura.get(car)){
							cout<<car;
							}
							flectura.close();
							flectura.open("Reportes/Empleados/EmpleadosDeServicio.txt");
						}
					break;
				}
				char car;
				while(flectura.get(car)){
					cout<<car;
				}
				flectura.close();
				system("pause");
				system("cls");
			break;
		}
	}while(opcion != 6);
}

int verNoPersonas(Habitacion* habitacion){
	return habitacion->noPersonas;
}
