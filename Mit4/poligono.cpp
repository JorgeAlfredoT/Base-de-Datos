#include <iostream>
#include<cmath>
#include"poligono.h"
using namespace std;

///////////////////////////////////////Point
template<typename type>
Point<type>::Point(){
   x=0;
   y=0;
}

template<typename type>
Point<type>::Point(type px, type py){
  this->x=px;
  this->y=py;
}
template<typename type>
Point<type>::~Point(){
  ;
}
template<typename type>
void Point<type>::setX(const type new_x){
  this->x=new_x;
}
template<typename type>
void Point<type>::setY(const type new_y){
  this->y=new_y;
}

template<typename type>
type Point<type>::getX()const{
  return x;
}
template<typename type>
type Point<type>::getY()const {
  return y;
}
template<typename type>
void Point<type>::printPoint(){
  cout<<"("<<x<<","<<y<<")"<<endl;
}


////////////////////////////////////PointArray
template<typename type>
void PointArray<type>::resize(int n){
   //Point pnu(0,0);
   size = n;
   Point<type> *newpoints = new Point<type>[n];
   for(int e = 0; e < n; e++){
      // if(e == n - 1)
      //    newpoints[e]=pnu;
      // else
         newpoints[e] = data[e];
   }
   delete [] data;
   data=newpoints;
}

template<typename type>
PointArray<type>::PointArray(){
  this->size=0;
  this->data= new Point<type>[size];
}
template<typename type>
PointArray<type>::~PointArray(){
  delete [] data;
}
template<typename type>
PointArray<type>::PointArray(PointArray &o){
  this->size=o.size;
  this->data=new Point<type>[o.size];
 }
template<typename type>
PointArray<type>::PointArray(const Point<type> gg[],const int nuevo_size){
  this->size=nuevo_size;
  this->data= new Point<type>[nuevo_size];
  int e=0;
  for(;e<nuevo_size;e++){
    this->data[e]=gg[e];
  }
}
template<typename type>
int PointArray<type>::getSize()const{
   return size;
}
template<typename type>
void PointArray<type>::printPointArray(){
   int e=0;
   for (Point<type> *p=data ;e<size ; p++,e++){
      cout<<"("<<p->getX()<<","<<p->getY()<<")  ";
   }
   cout<<endl;
}
template<typename type>
void PointArray<type>::p_back(const Point<type> &anh){ // const Point &p
   resize(size + 1);
   //cout<<size<<endl; // size actualizado
   Point<type> *p = data;
   p[size - 1 ] = anh;
}
template<typename type>
void PointArray<type>::insert(const int position, const Point<type> &anh){
   resize(size+1);
   for (int e = size-1; e > position ; e--) {
        data[e] = data[e - 1];
    }
    data [position] = anh ;
}
template<typename type>
void PointArray<type>::remove(const int position){
   for(int e = 0 ; e<size ;e++){
      if(e != position)
         continue;
      else if (e == position)
         data[e] = data[e+1];
         break;
   }
   for(int e = position +1 ; e<size ;e++){
      data[e]=data[e+1];
   }
   resize(size-1);
}
template<typename type>
void PointArray<type>::clear(){
   resize(0);
}
/////////////////////////////poligono////////////////////////////
template<typename type>
int Poligono<type>::cantPoligonos = 0;
template<typename type>
Poligono<type>::Poligono(const Point<type> gg[], const int lenarray) : listapoints(gg,lenarray){
   cantPoligonos++;
}

template<typename type>
Poligono<type>::~Poligono(){cantPoligonos--;}

template<typename type>
Poligono<type>::Poligono(const PointArray<type> &arr): listapoints(arr) {
   cantPoligonos++;
}

///////////////////////////////////7rectangulo
template<typename type>
Rectangulo<type>::Rectangulo(const Point<type> &a, const Point<type> &b, const Point<type> &c, const Point<type> &d){
   points[0] = (a.getX(),a.getY());
   points[1] = (b.getX(),b.getY());
   points[2] = (c.getX(),c.getY());
   points[3] = (d.getX(),d.getY());
}
template<typename type>
float Rectangulo<type>::area()const{
   float altura = points[1].getY() - points[0].getY();
   float base = points[2].getX() - points[1].getX();
   return base + altura;
}
/////////////////////triangulo77/////////////

template<typename type>
Triangulo<type>::Triangulo(const Point<type> &a,const Point<type> &b, const Point<type> &c){
   points[0] = (a.getX(), a.getY());
   points[1] = (b.getX(), b.getY());
   points[2] = (c.getX(), c.getY());
}
template<typename type>
float Triangulo<type>::area()const{
   float lado = pow((points[1].y - points[0].y),2);
   lado = sqrt(lado);
   return lado;
}


int main(){
  PointArray<int> *pa;
  Point<int> p1(1,1);
  Point<int> p2(2,2);
  Point<int> p3(3,3);
  Point<int> p4(4,4);
  Point<int> p5(5,5);
  Point<int> p6(6,6);
  Point<int> lp[]={p1,p2,p3,p4};
  PointArray<int> listapoints(lp,4);
  listapoints.printPointArray();

  listapoints.p_back(p5);
  listapoints.printPointArray();

  listapoints.insert(3,p6);
  listapoints.printPointArray();

  listapoints.remove(2);
  listapoints.printPointArray();

  cout<<listapoints.getSize()<<endl;
  listapoints.clear();
  cout<<listapoints.getSize()<<endl;

Point<int> p11(0,0), p12(0,2), p13(3,2), p14(3,0);
Point<float> p15(0.0,0.0), p16(5,8.660254038), p17(10,0);

  return 0;
}
