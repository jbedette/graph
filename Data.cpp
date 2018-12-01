#include "head.h"

//John Bedette, cs163, driected graph
//Data object to conveniently hold relevant Vertex data




Data::Data(){
  title = NULL; 
  text = NULL;
}



Data::~Data(){
  delete title;
  delete text;
}



//displays Data values
//displays errors with malformed
int Data::disp(){
  using namespace std;
  if(!title){
    cout <<"\nErr: no title, malformed Data\n";
    return 0;
  }
  if(!text){
    cout <<"\nErr: no text, malformed Data\n";
    return 0;
  }
  //

  cout << "\n\n"
    << title << "\n"
    << "==========" << "\n"
    << text << "\n"
    << "==========";
  return 1;
}
