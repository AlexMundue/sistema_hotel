#include <iostream>
#include "Cliente.cpp"
#include "Gerente.cpp"
#include <string.h>

using namespace std;

int main(){
	//codigo = codigo de empleado
	int opcion = 0, codigo = 0;
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
							if(maxEmpleados > Empleado::noEmpleados && maxGerentes > Gerente::noGerentes){
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
								if(opcion == 1){
									empleados[ID] = new Gerente(nombre,telefono,direccion,RFC,ID);
									Gerente::aumentarGerentes();
								}
								Empleado::agregarEmpleado();
								cout<<"Se a creado satisfactoriamente el nuevo registro."<<endl;
							}else {
								//Este caso es en dado caso que alguna de las condiciones de limite de empleado se presente
								if(maxEmpleados <= Empleado::noEmpleados){
									cout<<"-Numero maximo de empleados: "<<maxEmpleados<<"\tActualmente: "<<Gerente::noEmpleados<<endl;
								}
								if(maxGerentes <= Gerente::noGerentes){
									cout<<"-Numero maximo de gerentes: "<<maxGerentes<<"\tActualmente: "<<Gerente::noGerentes<<endl;
								}
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
							int id = 0;
							cout<<"Ingresa el codigo del registro a eliminar: ";
							cin>>id;
							if(empleados[id] != NULL){
								delete empleados[id];
								empleados[id] = NULL;
								Gerente::disminuirGerentes();
								cout<<"El registro se ha eliminado correctamente."<<endl;
							}else {
								cout<<"El ID ingresado no está registrado a un empleado."<<endl;
							}
							system("PAUSE");
							system("cls");
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
						if(maxClientes > Cliente::numeroClientes){
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
							ID = Cliente::numeroClientes;
							clientes[Cliente::numeroClientes] = new Cliente(email, nombre, telefono, direccion, RFC, ID);
							Cliente::aumentarClientes();
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
						if(Cliente::numeroClientes != 0){
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
