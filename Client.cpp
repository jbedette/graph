#include "head.h"
#include <fstream>
//uses cstring
//uses namespace std

Client::Client(){
  ifstream fin;
  fin.open("data.txt");
  if(!fin) cout << "\nFile not found, aborting";
  else{

    int size = 0;//# of vertices to be read in
    int id = 0;//id of vertex to be read in
    char eolChar = ' ';//to detect end of edge targId
    bool eol = false;
    char temp[300];
    //testing
    int count = 0;
    //

    fin >> size;
    fin.ignore(1000,'\n');
    game = new Game(size); 


    while(fin >> id && !fin.eof()){
      Edge * tEdge = new Edge;
      Edge * tEdgeHold = tEdge;
      Data * tData = new Data;
      Vertex * tVert = new Vertex(tEdge,tData);//sets Edge and Data to new blanks of each
      tVert->id = id; 

      //tdata fill
      fin.ignore(1000,'|'); 
      fin.get(temp,25,'\n');
      tData->title = new char[strlen(temp)+1];
      strcpy(tData->title, temp);
      fin.ignore(1000,'|'); 
      fin.get(temp,299,'|');//might run into issues here wit delim
      tData->text = new char[strlen(temp)+1];
      strcpy(tData->text, temp);
      fin.ignore(1000,'|');//might run into issues here wit delim

      //edge list fill
      while(!eol){
        tEdgeHold = tEdge;
        fin >> tEdge->targId;
        fin.ignore(1000,'|');
        fin >> eolChar;
        fin.ignore(1000,'|');
        eol = eolCheck(eolChar);
        if(!eol){
          tEdge = new Edge;
          tEdgeHold->next = tEdge;
        }
      }
      fin.ignore(1000,'\n');
      game->add(tVert);
      ++count;
    }
    //game->setEdges();
    //testing graph population
    cerr << "\nTotal Vertices added" << count;
    cerr << "\nTotal Edges set: " << game->setEdges();
    //
  }
}

Client::~Client(){
  delete game;
}

void Client::dispAll(){
  int vertexCount = 0;
  int edges = game->dispAll(vertexCount);
  cout 
    << "\nCount of Vertices: " << vertexCount
    << "\nCount of Edges: " << edges;

}



