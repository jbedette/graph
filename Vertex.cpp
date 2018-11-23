#include "head.h"

Vertex::Vertex(Edge * tEdge, Data * tData){
  data = tData;
  head = tEdge;
  id = 0;
}
Vertex::~Vertex(){
  delete head;
  delete data;
}
