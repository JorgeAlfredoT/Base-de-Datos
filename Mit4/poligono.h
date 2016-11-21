#ifndef POLIGONO_H
#define POLIGONO_H
template<typename type>
class Point{
private:
  type x,y;
public:
  Point();
  Point(type,type);
  ~Point();
  void setX(const type new_x);
  void setY(const type new_y);
  type getX()const;
  type getY()const;
  void printPoint();
};

template<typename type>
class PointArray{
private:
  int size;
  Point<type> *data;
  void  resize(int n);
public:
  PointArray();
  ~PointArray();
  PointArray(PointArray &o);
  PointArray(const Point<type> [],const int);
  void printPointArray();
  int getSize()const;
  void p_back(const Point<type> &);
  void insert(const int, const Point<type> &);
  void remove(const int);
  void clear();
  Point<type> *get(const int);
  Point<type> *get(const int) const;

};

template<typename type>
class Poligono{
protected:
   PointArray<type> listapoints;
   static int cantPoligonos;
public:
   Poligono(const Point<type> listapoints[], int lenarray);
   Poligono(const PointArray<type> &arr);
   ~Poligono();
   virtual float area() const =0;
   static int getNumPoligonos(){return cantPoligonos;}
   int getNumLados()const{return listapoints.getSize();}
   const PointArray<type> *getPoints()const {return &listapoints;}

};
template<typename type>
class Rectangulo: public Poligono<type> {
private:
   Point<type> points[4];
public:
   Rectangulo(const Point<type> &, const Point<type> &);
   Rectangulo(const Point<type> &a, const Point<type> &b, const Point<type> &c, const Point<type> &d);
   virtual float area()const;
};
template<typename type>
class Triangulo : public Poligono<type>{
private:
   Point<type> points[3];
public:
   Triangulo(const Point<type> &p1, const Point<type> &p2, const Point<type> &p3);
   virtual float area()const;
};


#endif
