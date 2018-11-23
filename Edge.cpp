#include "head.h"
//error highlighting: /////

Edge::Edge(){
  adj = NULL;
  next = NULL;
  targId = -1;
}
Edge::~Edge(){
  delete next;
}
int Edge::disp(){
  using namespace std;
  if(adj == NULL){
    cout << "\n/////Err: malformed Edge, no adjacent pointer\n";
    return 0;
  }
  if(adj->id != targId){
    cout << "\n/////Err: malformed Edge, adj point != targId\n";
    return 0;
  }
  cout << "\nAdj: " << adj->data->title;
  return 1;
}
