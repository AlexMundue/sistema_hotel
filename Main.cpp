#include <iostream>
#include "Cliente.cpp"
#include "Gerente.cpp"
#include "Administrador.cpp"
#include "EmpleadoDeServicio.cpp"
#include <string.h>
#include <typeinfo>

using namespace std;

int main(){
	
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
	Persona* clientes[maxClientes];
	for(int i = 0; i < maxClientes; i++){
		clientes[i] = NULL;
	}
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
								int telefono;
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
								
								//En dado caso que ya esté el límite de empleados de un tipo, se informa el número actual
								if(opcion == 1 && Gerente::noGerentes >= maxGerentes) {
									cout<<"-Numero maximo de gerentes: "<<maxGerentes<<"\tActualmente: "<<Gerente::noGerentes<<endl;
								}else if(opcion == 2 && Administrador::noAdministradores >= maxAdministradores) {
									cout<<"-Numero maximo de Administradores: "<<maxAdministradores<<"\tActualmente: "<<Administrador::noAdministradores<<endl;
								}else if(opcion == 3 && EmpleadoDeServicio::noEmpleadosDeServicio >= maxEmpleadosDeServicio) {
									cout<<"-Numero maximo de empleados de servicio: "<<maxEmpleadosDeServicio<<"\tActualmente: "<<EmpleadoDeServicio::noEmpleadosDeServicio<<endl;
								}
								empleados[ID]->reportar();
								empleados[ID]->reportarPorTipo();
								Empleado::agregarEmpleado();
								cout<<"Se a creado satisfactoriamente el nuevo registro."<<endl<<"ID: "<<ID<<endl;
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
								if(empleados[id] != NULL){
									//Se compara que tipo de empleado se eliminó, para así disminuir el contador de ese tipo de empleado y así continuar teniendo el conteo
									if(typeid(Gerente) == typeid(*(empleados[id]))){
										Gerente::disminuirGerentes();
										cout<<"Gerentes: "<<Gerente::noGerentes;
									}
									else if(typeid(Administrador) == typeid(*(empleados[id]))){
										Administrador::disminuirAdministradores();
										cout<<"Administradores: "<<Administrador::noAdministradores;
									}
									else if(typeid(EmpleadoDeServicio) == typeid(*(empleados[id]))){
										EmpleadoDeServicio::disminuirEmpleadosDeServicio();
										cout<<"EmpleadoDeServicio: "<<EmpleadoDeServicio::noEmpleadosDeServicio;
									}
									delete empleados[id];
									empleados[id] = NULL;
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
							int telefono;
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
			break;
			
			case 4:
				cout<<"Ingresa codigo de empleado: "<<endl;
				cin>>codigo;
				//Poner precios de las habitaciones
				cout<<"Habitacion Doble: $"<<endl;
				cout<<"Habitacion Cuadruple: $"<<endl;
				cout<<"Habitacion de Lujo: $"<<endl;
			break;
			
			case 5:
				cout<<"1. Lista de Clientes"<<endl<<"2. Lista de Habitaciones totales"<<endl<<"3. Reporte de Habitaciones disponibles"<<endl<<"4. Reporte de Habitaciones NO disponibles."<<endl
				<<"5. Lista de Empleados"<<endl<<"6. Lista de Empleados de acuerdo a tipos."<<endl;
			break;
		}
	}while(opcion != 6);
}
