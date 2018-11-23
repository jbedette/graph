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
    char temp[300];
    //testing
    int count = 0;
    //

    fin >> size;
    fin.ignore(1000,'\n');
    game = new Game(size); 


    while(fin >> id && !fin.eof()){
      char eolChar = ' ';//to detect end of edge targIds in data.txt
      bool eol = false;//end of line

      Edge * tEdge = new Edge;
      Data * tData = new Data;
      Vertex * tVert = new Vertex(tEdge,tData);//sets Edge and Data to new blanks of each
      cerr << "\nAddr tVert: " << tVert;

      //vert id fill
      tVert->id = id; 
      fin.ignore(1000,'|'); 
      //cerr << "\nid: " << tVert->id;
      //tdata fill
      fin.get(temp,25,'|');
      tData->title = new char[strlen(temp)+1];
      strcpy(tData->title, temp);
      //cerr << "\ntitle: " << tData->title;
      fin.ignore(1000,'|'); 

      fin.get(temp,299,'|');//might run into issues here wit delim
      tData->text = new char[strlen(temp)+1];
      strcpy(tData->text, temp);
      //cerr << "\ntext: " << tData->text << "\n=========";
      //cerr << "\ntitle: " << tData->title;
      fin.ignore(1000,'|');

      //edge list fill
      fin >> eolChar;
      eol = eolCheck(eolChar);
      cerr << "\n\neol: " << eolChar;
      fin.ignore(1000,'|');
      cerr << "\ntitle: "<< tData->title;
      if(eol) tEdge->adj = NULL;
      else{
        while(!eol){
          fin >> tEdge->targId;
          fin.ignore(1000,'|');
          cerr << "\ntargId: " << tEdge->targId;
          fin >> eolChar;
          fin.ignore(1000,'|');
          eol = eolCheck(eolChar);
          cerr << "\neol?: " << eolChar;
          if(!eol){
            Edge * tEdgeHold = tEdge;
            cerr << " +addnew, tedge old: " << tEdge;
            tEdge = NULL;
            tEdge = new Edge;
            cerr << ", new: " << tEdge;
            tEdgeHold->next = tEdge;
            cerr << ", tHold: " << tEdgeHold << ", tHold->n: " << 
              tEdgeHold->next;
          }
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



