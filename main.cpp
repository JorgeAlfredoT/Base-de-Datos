#include <iostream>
#include <fstream>
#include <ctype.h>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "cliente.h"
using namespace std;


void Menu(){
	cout << "\n\n" ;
	cout << "\t\t\t\tMENU PRINCIPAL" << endl;;
	cout << "\t\t 1.- Altas. " << endl;
	cout << "\t\t 2.- Bajas. " << endl;
	cout << "\t\t 3.- Consultas. " << endl;
	cout << "\t\t 4.- Modificaciones" << endl;
	cout << "\t\t 5.- Salir" << endl;
	cout << "\t\t 6.- Mostrar. " << endl;
	cout << "\n\t\telige una opcion " << endl;
}



int main(){

	int iclave;
	int iop, ij;
	char ope = 'n';

	ifstream salida;
	ofstream entrada;

	empleado emp;


	do{
		Menu();
		cout << "\t\t";
		cin >> iop;
		switch(iop){
			case 1:
				//system("clear");
				entrada.open("penny.txt",ios::out | ios::app);
				do{
					emp.pedirdatos();
					entrada.write( (char*) &emp, sizeof(emp));
					cout << "\n\n\t\tDesea otro registro ?: ";
					cin >> ope;
				} while(toupper(ope) == 'S');
				entrada.close();
				break;

			case 2:
				//system("clear");
				salida.open("penny.txt", ios::in);
				entrada.open("temp.txt", ios::out | ios::app);
				cout << "introduzca la clave del registro a eliminar"; cin>> iclave;

				while( salida.read( (char*) &emp, sizeof(emp) ) != 0 ){
					if(emp.getClave() != iclave)
						entrada.write( (char*) &emp,sizeof(emp) );
					else
						cout << "eliminacionn exitosa" << endl;
				}
				salida.close();
				entrada.close();

				remove("penny.txt");
				rename("temp.txt","penny.txt");
				break;

			case 3:
				//system("clear");
				salida.open("penny.txt",ios::in);
				cout << "introdusca la clave del registro a cons.", cin >> iclave;

				while( salida.read( (char*) &emp, sizeof(emp) ) != 0 ){
					if(emp.getClave() == iclave){
						//system("clear");
						emp.consultas();
					}
				}
				salida.close();
				break;

			case 4:
				//system("clear");
				salida.open("penny.txt",ios::in);
				entrada.open("temp.txt" ,ios::out | ios::app);
				cout << "clave de registro a modificar: "; cin >> iclave;

				while(salida.read( (char*) &emp, sizeof(emp) ) != 0 ){
					if(emp.getClave() == iclave){
						emp.modificar();
						entrada.write( (char*)& emp, sizeof(emp) );
						cout << "modificacion exitosa " << endl;
					}
					else
						entrada.write( (char*)& emp, sizeof(emp) );	
				}
				salida.close();
				entrada.close();
				remove("penny.txt");
				rename("temp.txt","penny.txt");
				break;

			case 6:
				salida.open("penny.txt", ios::in);
				while( salida.read( (char*)&emp, sizeof(emp) ) != 0){
					emp.datos_constantes();
					cout << "\n";
				}
				salida.close();
				break;

		} 
	} while(iop != 5);


	return 0;
}