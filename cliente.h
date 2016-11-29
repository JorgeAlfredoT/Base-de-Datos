#ifndef CLINTE_H
#define CLINTE_H

class empleado{
protected:
	int clave;
	char nombre[15];
	int dias;
	float sueldodiario;
public:
	empleado();
	~empleado(){}

	int getClave();
	void desplegar(int);
	void pedirdatos();
	void modificar();
	void consultas();
	void datos_constantes();

};


#endif