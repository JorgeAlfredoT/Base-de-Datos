#ifndef STACK_H
#define STACK_H

template<typename type>
class Stack{
private:
   int size;
   type *data;
   void resize(int);
public:
   Stack();
   ~Stack();
   Stack(Stack &);
   bool empty();
   void push(const type &);
   type top();
   void pop();
   void printStack();
   type getSize();
   //Stack<type> operator + (Stack<type> list);
};

#endif
