#include "head.h"

//John Bedette, cs163, driected graph
//Vertex contains pointers to all relevant data



//edge and data passed in and set upon creation
Vertex::Vertex(Edge * tEdge, Data * tData){
  data = tData;
  head = tEdge;
  id = 0;
}
Vertex::~Vertex(){
  delete head;
  delete data;
}
