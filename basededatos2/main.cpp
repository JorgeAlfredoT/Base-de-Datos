#include<iostream>
#include"datos.cpp"
#include"datos.h"
using namespace std;



int main(){

   // char *nombre[] ="jorge";
   // char *apell1[]="bellido";
   // char *apell2[] = "alvares";
   // char *depart[]= "cusco";
   // short edad = 20;
   // int dni = 12345;
   // int notas = 20;




   //Datos<int> d0;
   //Datos<int> d1("jorge","quispe","corahua","arequipa",21,12345,23);

   ListaDatos<int> ld1;
   ld1.agregar();
   ld1.mostrar();
   cout << ld1.getSize() << endl;
   ld1.modificar();

   ld1.eliminar();

   return 0;
}
