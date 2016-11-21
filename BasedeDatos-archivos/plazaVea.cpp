
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;



int main(){

   ofstream entrada;
   ifstream salida;

   entrada.open("plazavea.txt",ios::out | ios::app);
   char producto[10];
   char marca[10];
   float precio;
   for(int e = 0 ; e<3; e++){
      cout<<"producto: "; cin>>producto;
      cout<<"marca: ";  cin>>marca;
      cout<<"precio: "; cin>>precio;
      entrada << producto << " " << marca << " " << precio << endl;
   }
   entrada.close();
   ///////////////////////// salida ///////////////////////////////////
   salida.open("plazavea.txt",ios::in);
   if(salida.fail())
      cout<<"hubo un problem con la salida"<<endl;
   else
      cout<<"Salida con exito"<<endl;
      salida >> producto;
      while(!salida.eof()){
         salida >> marca;
         salida >> precio;
         cout << "veras: " << producto << " " << marca << " " << precio << endl;
         salida >> producto;
      }
   salida.close();
   ////////////////////////////////////////
   //eliminando
   //creando un temporal

   ofstream entrada1;
   ifstream salida1;
   salida1.open("plazavea.txt",ios::in);
   entrada1.open("temporal.txt",ios::out | ios::app);
   char aux[20];
   cout<<"Producto que desea eliminar: "; cin >> aux;
   salida1 >> producto;
   while(!salida1.eof()){
      salida1 >> marca >> precio ;
      if( strcmp(aux,producto) == 0 ){
         cout<<"se ha borrado"<<endl;
      }
      else{
         entrada1 << producto << " " << marca << " " << precio << endl;
      }
      salida >> producto;
   }
   salida1.close();
   entrada1.close();
   remove("plazavea.txt");
   rename("temporal.txt", "plazavea.txt");





















   return 0;
}
