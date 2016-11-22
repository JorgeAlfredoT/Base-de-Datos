#include<iostream>
using namespace std;

template <typename type>
class Graph{
    map<int, vector<int>> mapa1;
  public:
    Graph ( const vector <int > &starts , const vector <int > &ends ){
      for( int i = 0; i < starts.size (); i++ ) {
          int o = starts[i];
          int d = ends[i];
          mapa1[o].push_back(d);
      }
    }
};








int main(){





  return 0;
}
