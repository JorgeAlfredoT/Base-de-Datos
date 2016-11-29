#include <iostream>
#include <vector>
using namespace std;

class Node{
protected:
  Node *sgte;
  Node *ant;
  int val;

public:
  Node(int newval = 0): val(newval), sgte(NULL), ant(NULL){}
  ~Node(){}
};


class Grafo{
protected: 
  Node *raiz;
  int nroBordes;
public:
  Grafo(): raiz(NULL), nroBordes(0){}
  ~Grafo(){}
  Grafo(vector const &start, vector const &end); 
  Ordenar_Arbol(Node *raiz);

};


Grafo::Grafo(vector const &start, vector const &end){
  int temp;
  vector<int>::iterator it;
  start.end() = temp;

  for(int e = 0 ; e < end.size() < ; e++)
    start.push_back(end[e]);

  Ordenar(start[e]);

}




int main(){

  return 0;
}