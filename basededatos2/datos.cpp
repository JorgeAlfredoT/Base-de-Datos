#include<iostream>
#include<cstring>
#include"datos.h"
#include<fstream>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;

/////////////////////// desarrollo de la clase Datos////////////////////////////
///desarrollo de constructores de Datos///////////////////////////////////////////////////////////
template<typename type>
Datos<type>::Datos(char *newnom, char *newPApell, char *newSApell, char *newdepar, short newedad,char *newdni, type newnotas){
   setNombre(newnom);
   setprimerApellido(newPApell);
   setsegundoApellido(newSApell);
   setDepartamento(newdepar);
   setEdad(newedad);
   setDni(newdni);
   setNotas(newnotas);
}
// template<typename type>
// Datos<type>::Datos(){
//    for(int e = 0 ; e<12 ; e++){
//       nombre[e] = '\0';
//       primerApellido[e] = '\0';
//       segundoApellido[e] = '\0';
//       departamento[e] = '\0';
//    }
//    edad = 0;
//    dni = 0;
//    notas = 0;
// }
template<typename type>
Datos<type>::~Datos(){
   ;
}
/////////////desarrollo de los metodos de la clase Datos///////////////////////////////////////

template<typename type>
void Datos<type>::setNombre(char *ptrnombre){
   strcpy(nombre,ptrnombre);
   // for(int e = 0 ; (ptrnombre[e] != '\0') && e < 12 ; e++){
   //    nombre[e] = ptrnombre[e];
   // }
}

template<typename type>
void Datos<type>::setprimerApellido(char *ptr1apell){
   strcpy(primerApellido,ptr1apell);
   // for(int e = 0 ;(ptr1apell[e] != '\0') && e < 12 ; e++){
   //    primerApellido[e] = ptr1apell[e];
   // }
}

template<typename type>
void Datos<type>::setsegundoApellido(char *ptr2apell){
   strcpy(segundoApellido,ptr2apell);
   // for (int e = 0 ; (ptr2apell[e] != '\0') && e<12 ; e++){
   //       segundoApellido[e] = ptr2apell[e];
   // }
}

template<typename type>
void Datos<type>::setDepartamento(char *ptrdepart){
   strcpy(departamento,ptrdepart);
   // for (int e = 0 ;(ptrdepart[e] != '\0') && e < 12 ;  e++){
   //    departamento[e] = ptrdepart[e];
   // }
}

template<typename type>
void Datos<type>::setEdad(int newedad){
   this->edad = newedad;
}

template<typename type >
void Datos<type>::setDni(char *newdni){
   strcpy(dni,newdni);
}

template<typename type>
void Datos<type>::setNotas(type newnotas){
   this->notas = newnotas;
}


//desarrollo de la clase listaDatos///////////////////////////////////////////////////////////////////7
template<typename type>
ListaDatos<type>::ListaDatos(){
   size = 0;
   data = new Datos<type>[size];
}

template<typename type>
ListaDatos<type>::~ListaDatos(){
   delete [] data;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename type>
void ListaDatos<type>::resize(int newsize){
   size = newsize;
   Datos<type> *newdata = new Datos<type>[size]; // sizer actualizado
   for(int e = 0 ; e<size; e++){ // size actualizado
      newdata[e] = data[e];
   }
   delete [] data;
   data = newdata;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
 template<typename type>
   void ListaDatos<type>::agregar(){
   resize(size+1);
   //data[size - 1] ;


   char nombre[12];
   char primerApellido[12];
   char segundoApellido[12];
   char departamento[12];
   short edad;
   char dni[4];
   type notas;

   cout << "Nombre: "; cin >> nombre;
   cout << "Primer Apellido: "; cin >> primerApellido;
   cout <<"Segundo Apellido: "; cin >> segundoApellido;
   cout << " Departamento: "; cin >> departamento;
   cout << "Edad: "; cin >> edad;
   cout <<"DNI : "; cin >> dni;
   cout << "Notas: "; cin >> notas;

   Datos<int> dato_temp (nombre,primerApellido,segundoApellido,departamento,edad,dni,notas);
   data[size-1] = dato_temp;

   ofstream entrada; // ingresaremos al archivo
   entrada.open("relacion.txt", ios::out | ios::app);

   entrada<< nombre <<" "<< primerApellido<<" "<< segundoApellido <<" "<< departamento <<" "<< edad <<" "<< dni <<" "<< notas << endl;

   entrada.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename type>
void ListaDatos<type>::mostrar(){
   char nombre[12];
   char primerApellido[12];
   char segundoApellido[12];
   char departamento[12];
   short edad;
   char dni[4];
   type notas;

   ifstream salida;
   salida.open("relacion.txt", ios::in);

   salida >> nombre;
   while(!salida.eof()){
      salida >> primerApellido >> segundoApellido >> departamento >> edad >> dni >> notas ;
      cout << nombre << " " << primerApellido << " " << segundoApellido << " " << departamento << " " << edad << " " << dni << " " << notas << endl;
      salida >> nombre;
   }
   salida.close();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////7/////

template<typename type>
void ListaDatos<type>::eliminar(){

   char nombre[12];
   char primerApellido[12];
   char segundoApellido[12];
   char departamento[12];
   short edad;
   char dni[4];
   type notas;
   char compdni[4];

   bool entro = false;
   ifstream salida;
   ofstream entrada;
   salida.open("relacion.txt", ios::in);
   entrada.open("temp.txt", ios::out | ios::app);

   cout << "Dni de la persona que quiere eliminar: "; cin >> compdni;

   salida >> nombre;
   while(!salida.eof()){
      salida >> primerApellido >> segundoApellido >> departamento >> edad >> dni >> notas;
      if(strcmp(dni,compdni) == 0){
         entro = true;
         cout << " se ha eliminido correctamente !!!"<< endl;
      }
      else
         entrada << nombre <<" "<< primerApellido<<" "<< segundoApellido << " " << departamento <<" " << edad <<" "<< dni <<" "<< notas << endl;
      salida >> nombre;
   }
   if(!entro)
      cout << "No se ha encontrado el dato !!!" <<endl;

   remove("relacion.txt");
   rename("temp.txt", "relacion.txt");
}
////////////////////////////////////////////////////////////////////////////////////////////////////7
template<typename type>
int ListaDatos<type>::getSize(){
   return size;
}

///////////////////////////////////////////////////////////////////////////////////////////////////7/

template<typename type>
void ListaDatos<type>::modificar(){
   bool entro = false;
   char nombre[12];
   char primerApellido[12];
   char segundoApellido[12];
   char departamento[12];
   short edad;
   char dni[4];
   type notas;
   char compdni[4];


   char nombre_mod[12];
   char primerApellido_mod[12];
   char segundoApellido_mod[12];
   char departamento_mod[12];
   short edad_mod;
   char dni_mod[4];
   type notas_mod;


   ifstream salida;
   ofstream entrada;

   salida.open("relacion.txt", ios::in);
   entrada.open("temp.txt", ios::out | ios::app);

   cout << " DNI de la persona que desea modificar: "; cin >> compdni;

   salida >> nombre;
   while(!salida.eof()){
      salida >> primerApellido >> segundoApellido >> departamento >> edad >> dni >> notas;
      if(strcmp(dni,compdni) == 0){
         cout << "Nuevo nombre: "; cin >>nombre_mod;
         cout << "Nuevo 1er Apellido: "; cin >> primerApellido_mod;
         cout << "Nuevo 2do Apellido: "; cin >> segundoApellido_mod;
         cout << "Nuevo departamento: "; cin >> departamento_mod;
         cout << "Nueva edad: "; cin >> edad_mod;
         cout << "Nuevo DNI: "; cin >> dni_mod;
         cout << "Nueva nota: "; cin >> notas_mod;

         strcpy(nombre,nombre_mod);
         strcpy(primerApellido,primerApellido_mod);
         strcpy(segundoApellido,segundoApellido_mod);
         strcpy(departamento,departamento_mod);
         edad = edad_mod;
         strcpy(dni, dni_mod);
         notas = notas_mod;

         entro = true;
      }
      entrada << nombre <<" "<< primerApellido<<" "<< segundoApellido << " " << departamento <<" " << edad <<" "<< dni <<" "<< notas << endl;
      salida >> nombre;
   }
   if(!entro)
      cout << "No se ha encontrado el dato !!!" << endl;

   remove("relacion.txt");
   rename("temp.txt", "relacion.txt");
}

///////////////////////////////////////////////////////////////////////////////////////////////////7


//fin
