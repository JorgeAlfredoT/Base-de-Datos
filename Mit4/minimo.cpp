#include<iostream>

#define MINIMO(a,b) (a<b ? a : b)
template<typename I, typename F>
F minimo(I a, F b){
   return a<b ? a : b;
}

int main(){
   std::cout<<std::min(6,5)<<std::endl;
   std::cout<<minimo<int,float>(3,2.999)<<std::endl;
   std::cout<<MINIMO(2,2.22)<<std::endl;

   return 0;
}
