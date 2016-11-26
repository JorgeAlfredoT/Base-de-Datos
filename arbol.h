#ifndef ARBOL_H
#define ARBOL_H

#include"node.h"

template<typename type>
class arbol{
private:
    Node<type> *raiz;
    Node<type> *insertar(Node<type>*,Node<type>*);
    Node<type> *borrar(Node<type>*, type);
    type  getValder(Node<type>*);
    void preOrden(Node<type>*);
    void inOrden(Node<type>*);
    void postOrden(Node<type>*);
public:
    arbol();
    void crear(Node<type>*);
    void recorridos(int);
    void eliminar(type);
    ~arbol(){}
};


#endif
