#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;



int main(){
   ifstream sal;
   ofstream ent;
   int elimino = 0;

   sal.open("telefonos.txt",ios::in | ios::app);
   ent.open("temp.txt",ios::out | ios::app);


   char nombre[10];
   int edad;
   int tlf;
   char aux[10];

   cout << "Nonbre que desea eliminar: "; cin >> aux;

   sal >>nombre;
   while(!sal.eof()){
       sal >> edad >> tlf ;
      if(strcmp(aux,nombre) == 0){
         cout << "Se ha eliminado correctamente"<<endl;
         elimino = 1;
      }
      else
         ent << nombre << " " << edad << " "<< tlf << endl;
      sal >> nombre ;
   }
   if (!elimino)
      cout<<"No se encontromese dato"<<endl;
   sal.close();
   ent.close();

   remove("telefonos.txt");
   rename("temp.txt","telefonos.txt");

   return 0;
}
