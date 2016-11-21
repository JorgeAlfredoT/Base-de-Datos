#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;

void menu();
void insertar();
void eliminar();
void mostrar();
void modificar();


int main(){
   unsigned short opc;
   do{
      menu();
      cin >> opc;
      switch(opc){
         case 1 :
            system("clear");
            insertar();
            break;
         case 2:
            system("clear");
            eliminar();
            break;
         case 3:
            system("clear");
            mostrar();
            break;
         case 4:
            system("clear");
            cout<<"Salida correctamente del progarma"<<endl;
            break;
         case 5:
            system("clear");
            modificar();
            break;
         default:
            system("clear");
            cout<<"opcion incorrecta"<<endl;
      }
   } while(opc !=4);


   return 0;
}

void menu(){
   //system("clear");
   cout << "\n\n";
   cout <<"------------------------------------------"<<endl;
   cout << "| ****************MENU******************" <<endl;
   cout << "----------------------------------------"<<endl;
   cout << "1 --> INSERTAR"<< endl;
   cout << "2 --> ELIMINAR"<< endl;
   cout << "3 --> MOSTRAR"<<endl;
   cout << "4 --> SALIR" << endl;
   cout << "5 --> MODIFICAR" << endl;
}

void insertar(){
   char nombre[10];
   char nato[10];
   int edad;
   ofstream entrada;
   entrada.open("becarios.txt", ios::out | ios::app);
   cout << "Nombre: || "; cin>>nombre;
   cout << "Nato:   || "; cin >> nato;
   cout << "edad:   || "; cin >> edad;

   entrada << nombre << " " << nato << " " << edad << endl ;

   //system("clear");
   entrada.close();
}

void eliminar(){
   char nombremod[8];
   char nombre[8];
   char nato[8];
   int edad;

   cout<<"nombre a eliminar: || "; cin >> nombremod;
   ifstream salida21;
   ofstream entrada21;

   salida21.open("becarios.txt", ios::in);
   entrada21.open("temp.txt", ios::out | ios::app);

   salida21 >> nombre;
   while(!salida21.eof()){
      salida21 >> nato >> edad ;
      if( strcmp(nombre,nombremod) == 0)
         cout << "Se ha eliminado el dato. "<<endl;
      else
         entrada21 << nombre << " " << nato << " " << edad << endl;
      salida21 >> nombre;
   }

   salida21.close();
   entrada21.close();

   remove("becarios.txt");
   rename("temp.txt", "becarios.txt");
}

void mostrar(){
   ifstream salida;
   salida.open("becarios.txt", ios::in);

   char nombre[8];
   char nato[8];
   int edad;

   salida >> nombre ;
   while(!salida.eof()){ // mientras no sea el fin de el archivo
      salida >> nato >> edad ;
      cout << nombre << " " << nato << " " << edad << endl;
      salida >> nombre;
   }
   salida.close();
}

void modificar(){

   ifstream salida;
   ofstream entrada;
   salida.open("becarios.txt", ios::in);
   entrada.open("temp.txt", ios::out | ios::app);


   char nombre[8];
   char nombremod[8];
   char nato [8];
   char natomod [8];
   int edad;
   int edadmod;
   cout<<"Nombre a modificar: "<<endl; cin >> nombremod;
   cout<<"Nato a midificar: "<<endl; cin >> natomod;
   cout<<"Edad a modificar: "<<endl; cin >> edadmod;

   salida >> nombre;
   while(!salida.eof()){
      salida >> nato >> edad;
      if(strcmp( nombre,nombremod ) == 0){
         strcpy(nombre,nombremod);
         strcpy(nato,natomod);
         edad = edadmod;
      }
      entrada << nombre  << " " << nato << " " << edad << endl;
      salida >> nombre;
   }
   salida.close();
   entrada.close();

   remove("becarios.txt");
   rename("temp.txt", "becarios.txt");


}
