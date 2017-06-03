#include <iostream>
#include <cstring>
#include <cstdlib> // para atoi atof
#include "cliente.h"
using namespace std;



empleado::empleado(){
	dias = clave = 0;
	strcpy(nombre,"\0");
}

int empleado::getClave(){
	return clave;
}

void empleado::desplegar(int a){
	cout << clave << endl;
	cout << nombre << endl;
	cout << dias << endl; ;
	cout << sueldodiario;
}

void empleado::pedirdatos(){
	//system("clear");
	cout << "\t\t\taltas de una registro a un archivo secuencial" << endl;
	datos_constantes();

	cout << "clave: "; cin >> clave ;
	cout << "nombre: "; cin >> nombre;
 	cout << "cant de dias "; cin >> dias;
}


void empleado::modificar(){
	//system("clear");
	char nombrem[15];
	char diasm[3];
	char sueldodiariom[10];

	cout << "\t\t\tmodificacion a un registro a un archivo secuencial";
	datos_constantes();

	cout << "new name: "; cin >> nombrem;
	cout << "new day: "; cin >> diasm;
	cout << "new sueldo: "; cin >> sueldodiariom;

	if(diasm != '\0')
		dias = atoi(diasm);

	if(sueldodiariom != '\0')
		sueldodiario = atof(sueldodiariom);

	if(nombrem[0] != '\0'){
		strcpy(nombre,"?");
		strcpy(nombre,nombrem);
	}
}

void empleado::consultas(){
	cout << "\tconsultas de un registro en un archivo secuencial";
	datos_constantes();
}

void empleado::datos_constantes(){
	cout << "\n";
	cout << "\t\tclave del empleado: " << clave << endl;
	cout << "\t\tnombre del empleaado: " << nombre << endl;
	cout << "\t\tsueldo diario: " << sueldodiario << endl;
	cout << "\t\tnro de dias trabajados: " << dias << endl;
}