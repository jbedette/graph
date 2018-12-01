#include "head.h"


//John Bedette, cs163, driected graph
//Edge is a LLL that contains 

Edge::Edge(){
  adj = NULL;//holds pointer to adj Vertex
  next = NULL;//continue on list of adjacencies
  desc = NULL;//small blurb about edge
  targId = -1;//to be filled with index of adj Vertex
}



Edge::~Edge(){
  delete next;
  delete desc;
}


//displays edge, and the name of the vertex
//it is pointing to 
//detects malformed edges and throws an error if malformed
int Edge::disp(){
  using namespace std;
  if(!adj){
    cout << "\nDead End!\n";
    return 0;
  }
  if(adj->id != targId){
    cout << "\nErr: malformed Edge, adj point != targId\n";
    return 0;
  }
  cout << "\n" << desc << adj->data->title;
  return 1;
}
