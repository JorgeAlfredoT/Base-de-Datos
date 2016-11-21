#ifndef DATOS_H
#define DATOS_H
template<typename type>
class Datos{
protected:
   char nombre[12];
   char primerApellido[12];
   char segundoApellido[12];
   char departamento[12];
   short edad;
   char dni[4];
   type notas;
public:
   //Datos();
   Datos(char* = "" , char*  ="" , char* ="", char* ="", short = 0, char* = "", type = 0);
   ~Datos();
   void setNombre(char *);
   void setprimerApellido(char *);
   void setsegundoApellido(char *);
   void setDepartamento(char *);
   void setEdad(int);
   void setDni(char *);
   void setNotas(type);
};

template<typename type>
class ListaDatos: public Datos<type>{
protected:
   Datos<type> *data;
   int size;
   type codigo;
   void resize(int);
public:
   ListaDatos();
   ~ListaDatos();
   void agregar();
   void modificar();
   void eliminar();
   void mostrar();
   int getSize();
};

#endif
