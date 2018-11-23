#include "head.h"

//err highlighting = >>>>>

Data::Data(){
  title = NULL; 
  text = NULL;
}
Data::~Data(){
  delete title;
  delete text;
}
int Data::disp(){
  using namespace std;
  //error: check for malford data
  if(!title){
    cout <<"\n>>>>>Err: no title, malformed Data\n";
    return 0;
  }
  if(!text){
    cout <<"\n>>>>>Err: no text, malformed Data\n";
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
