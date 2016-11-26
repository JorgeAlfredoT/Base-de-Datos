#ifndef NODE_H
#define NODE_H

template<typename type>
class Node{
public:
  type val;
  Node *der;
  Node *izq;
  Node();
  Node(type);
  ~Node();
};

#endif
