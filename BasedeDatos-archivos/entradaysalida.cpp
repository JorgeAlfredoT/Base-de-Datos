#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int main(){

   ofstream entrada;
   ifstream salida;

   entrada.open("entrada.txt", ios::out | ios::app);// lo que hace ios es crear entrada.txt en caso no haya
   if(entrada.fail())
      cout<<"No se ha abierto correctamente el entrada.txt "<<endl;
   else
      cout<<"Se ha abierto correctament el txt "<<endl;
      char nombre[20];
      char apellido[15];
      int edad;


      strcpy(nombre,"jorge");
      strcpy(apellido, "tito");
      edad = 20;
      entrada << nombre << " " << apellido << " " << edad << endl; //sta es la forma de ingresar datos al txt
      cout<<"los datos se almacenaron correctamente"<<endl;

   entrada.close();

   salida.open("entrada.txt",ios::in);
   if(salida.fail())
      cout<<"No se ha abieto correctamente la salida.txt"<<endl;
   else
      cout<<"se ha abiertocorrectamenyte el salida.txt"<<endl;
      salida >> nombre; // sta es la manera de sacar datos del fichero
      while(!salida.eof()){ // mientra no llega al final
         salida >> apellido >> edad;
         cout << nombre << " " << apellido << " " << edad <<endl;
         salida >> nombre;
      }
      salida.close();

   return 0;
}
