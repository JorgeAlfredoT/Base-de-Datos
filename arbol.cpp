#include<iostream>
#include"arbol.h"
#include"node.cpp"

using namespace std;

template<typename type>
arbol<type>::arbol(){
    raiz = NULL;
}

template<typename type>
Node<type>* arbol<type>::insertar(Node<type> *raiz, Node<type> *nuevo){
    if(raiz == NULL){
        raiz = nuevo;
    }
    else{
        if(nuevo->val < raiz->val){
            nuevo->izq = insertar(raiz->izq,nuevo);
        }
        else{
            raiz->der = insertar(raiz->der,nuevo);
        }
    }

    return raiz;
}
template<typename type>
void arbol<type>::crear(Node<type> *q)
{
    raiz = insertar(raiz,q);
}

template<typename type>
void arbol<type>::preOrden(Node<type> *p){
    if(p != NULL){
        cout << p->val << ", ";
        preOrden(p->izq);
        preOrden(p->der);
    }
}

template<typename type>
void arbol<type>::inOrden(Node<type> *p){
    if(p != NULL){
        inOrden(p->izq);
        cout << p->val << ", ";
        inOrden(p->der);
    }
}

template<typename type>
void arbol<type>::postOrden(Node<type> *p){
    if(p != NULL){
        postOrden(p->izq);
        postOrden(p->der);
        cout << p->val << ", ";
    }
}

template<typename type>
void arbol<type>::recorridos(int tipo){
    switch(tipo){
        case 1:
            preOrden(raiz);
        break;

        case 2:
            inOrden(raiz);
        break;

        case 3:
            postOrden(raiz);
        break;

        default:
	         cout<<"Error! opcion invalida"<<endl;
	      break;
    }
}

template<typename type>
type arbol<type>::getValder(Node<type> *q){
    if(q->der == NULL){
        return q->val;
    }
    else{
        return getValder(q->der);
    }
}

template<typename type>
Node<type>* arbol<type>::borrar(Node<type> *p, type info){
    Node<type> *q;

    if(p != NULL){
        if(p->val == info){
            if(p->izq == NULL && p->der == NULL){
                delete p;
                p = NULL;
            }
            else{
                if(p->izq == NULL && p->der != NULL){
                    q = p->der;
                    delete p;
                    p = q;
                }
                else{
                    info = getValder(p->izq);
                    p->val = info;
                    p = p->izq;
                    p->der = borrar(p->der, info);
                }
            }
        }
        else{
            if(info < p->val){
                p->izq = borrar(p->izq, info);
            }
            else{
                p->der = borrar(p->der, info);
            }
        }
    }

    return p;
}

template<typename type>
void arbol<type>::eliminar(type info){
    raiz = borrar(raiz, info);
}





























///
