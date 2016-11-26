#include<iostream>
#include"node.h"

template<typename type>
Node<type>::Node(){
  val = 0;
  der = NULL;
  izq = NULL;
};


template<typename type>
Node<type>::Node(type newval){
  val = newval;
  der = NULL;
  izq = NULL;
};

template<typename type>
Node<type>::~Node(){
  ;
}
