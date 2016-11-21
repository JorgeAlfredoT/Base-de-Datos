#include<iostream>
#include"stack.h"
#define ERROR_VACIA ("lA PILA YA ESTA VACIA")
using namespace std;

template<typename type>
Stack<type>::Stack(){
   size = 0;
   data = new type[size];
}
template<typename type>
Stack<type>::~Stack(){
   delete [] data;
}
template<typename type>
Stack<type>::Stack(Stack &o){
   size = o.size;
   data = new type[size];
}

template<typename type>
void Stack<type>::resize(int newsize){
   size = newsize;
   type *newdata = new type[size];
   for (int e = 0 ; e<size; e++)
      newdata[e] = data[e];
   delete [] data;
   data = newdata;
}

template<typename type>
bool Stack<type>::empty(){
   if(size <= 0)
      return true;
   return false;
}
 template<typename type>
 void Stack<type>::push(const type &elem){
    resize(size + 1);
    data[size - 1] = elem;
}

template<typename type>
type Stack<type>::top(){
   return data[size -1];
}

template<typename type>
void Stack<type>::pop(){
   if (!empty()){
      type temp = data[size - 1];
      resize(size - 1);
      cout<<temp<<endl;
   }
   else
      cout<<ERROR_VACIA<<endl;
}

template<typename type>
void Stack<type>::printStack(){
   for (int e = 0 ; e<size ; e++){
      cout<<data[e]<<"  ";
   }
   cout<<endl;
}

template<typename type>
type Stack<type>::getSize(){
   return size;
}

// template<typename type>
// Stack<type> Stack<type>::operator + (Stack<type>  list){
//    int lenlist = list.size;
//    Stack<type> *p = list;
//    for(int e = 0 ; e<lenlist ; e++,p++){
//       resize(size + 1);
//       data[size - 1] = *p;
//    }
// }

int main(){

   Stack<float> p1,p2;
   p1.push(12.3);
   p1.push(22.1);
   p1.push(15.43);
   p1.push(32.7);
   p1.printStack();
   p1.pop();
   cout<<p1.top()<<endl;


   cout<<endl;
   p1.pop();
   p1.printStack();
   p1.pop();
   p1.printStack();
   p1.pop();
   p1.printStack();
   p1.pop(); // ya esta vacia
   p1.pop(); // ya esta vacia


   p2.push(1000.0);
   p2.push(2000.0);
   // Stack<float> p3 = p1 + p2;
   // p3.printStack();






   return 0;
}
