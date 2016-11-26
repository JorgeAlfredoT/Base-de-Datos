#include <iostream>
//#include <stdio.h>
#include <cstring>
using namespace std;

#include"arbol.h"
#include"arbol.cpp"


void printMenu(){
    cout<<"\t\tMENU"<<endl;
    cout<<"1.Insertar"<<endl;
    cout<<"2.Recorrer"<<endl;
    cout<<"3.Eliminar"<<endl;
    cout<<"4.Salir"<<endl;
    cout<<endl<<"\tOPCION: ";
}

void printSubMenu(){
    cout<<endl<<"1.Imprimir en pre-orden"<<endl;
    cout<<"2.Imprimir en in-orden"<<endl;
    cout<<"3.Imprimir en post-orden"<<endl;
    cout<<endl<<"\tOPCION: ";
}

int main(){

    arbol<int> *arb1 = new arbol<int>();
    Node<int> *q;
    int aux = 0;
    int opcion;
    bool salir = false;

    do{
      printMenu();
      cin >> opcion;

      switch(opcion){
          case 1:
              cout<<endl<<"Ingrese un valor entero: ";
              cin>>aux;
              q = new Node<int>(aux);
              arb1->crear(q);
          break;

          case 2:
              printSubMenu();
              cin>>aux;
              arb1->recorridos(aux);
              cout<<endl<<endl;
          break;

          case 3:
              cout<<endl<<"Ingrese valor a eliminar: ";
              cin>>aux;
              arb1->eliminar(aux);
          break;

          case 4:
              cout<<"Cerrando aplicacion..." << endl;
              salir = true;
              break;

          default:
              cout<<endl<<"\tOpcion invalida!"<<endl;
          break;
      }

    }while(salir != true);


    return 0;
}
