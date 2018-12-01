#include "head.h"
#include <fstream>
#include <cstring>

//John Bedette, cs163, driected graph
//Client interacts with the user and reads in data


//Upon creation, the game client immediately starts 
//reading from the data.txt file and creating the graph
//
//while reading, the file, the Vertex needs to be assigned an unknown number of edges
//the function scans for an end of line input character(x)
//and will keep creating new edges and assigning them to the nascent Adjacency list
//while it doesn't find the escape character
//if the Vertex is meant to have no adjacencies, 
//the edge remans blank and the Edge assignment loop is never entered
//
//the vertex is assembled here completely and passed to the ADT
Client::Client(){
  ifstream fin;
  fin.open("data.txt");
  if(!fin) cout << "\nERR:File not found, aborting";
  else{

    int size = 0;//# of vertices to be read in
    int id = 0;//id of vertex to be read in
    char temp[300];
    int count = 0;

    fin >> size;
    fin.ignore(1000,'\n');
    game = new Game(size); 

    while(fin >> id && !fin.eof()){
      char eolChar = ' ';//to detect end of edge targIds in data.txt
      bool eol = false;//end of line

      Edge * tEdge = new Edge;
      Data * tData = new Data;
      Vertex * tVert = new Vertex(tEdge,tData);//sets Edge and Data to new blanks of each

      //vert id fill
      tVert->id = id; 
      fin.ignore(1000,'|'); 
      //tdata fill
      fin.get(temp,25,'|');
      tData->title = new char[strlen(temp)+1];
      strcpy(tData->title, temp);
      fin.ignore(1000,'|'); 

      fin.get(temp,299,'|');//might run into issues here wit delim
      tData->text = new char[strlen(temp)+1];
      strcpy(tData->text, temp);
      fin.ignore(1000,'|');

      //edge list fill
      fin >> eolChar;
      eol = eolCheck(eolChar);
      fin.ignore(1000,'|');
      if(eol){
        tEdge->adj = NULL;
      }else{
        while(!eol){
          fin >> tEdge->targId;
          fin.ignore(1000,'|');
          fin.get(temp,25,'|');
          fin.ignore(1000,'|');
          tEdge->desc = new char[strlen(temp)+1];
          strcpy(tEdge->desc,temp);

          fin >> eolChar;
          fin.ignore(1000,'|');
          eol = eolCheck(eolChar);
          if(!eol){
            Edge * tEdgeHold = tEdge;
            tEdge = NULL;
            tEdge = new Edge;
            tEdgeHold->next = tEdge;
          }
        }
      }
      fin.ignore(1000,'\n');
      game->add(tVert);
      ++count;
    }
    cout << "\nTotal Vertices added: " << count;
    cout << "\nTotal Edges assigned: " << game->setEdges();
  }
}




Client::~Client(){
  delete game;
}



//Displays all, displays count of adjacencies & Vertices
void Client::dispAll(){
  int vertexCount = 0;
  int edges = game->dispAll(vertexCount);
  cout 
    << "\nCount of Vertices: " << vertexCount
    << "\nCount of Adjacencies: " << edges;

}

//CAN USE DEPTH FIRST to set farthest node edge to v0
//inserts an edge into the last vertex
//the edge is a pointer back to vertex 0
//sends player there, removes end node
void Client::addEdge(){
  int curr =  game->depth();
  cerr << "\ncurr to add to: " << curr;
  int dest = 0;//the first node
  char desc[100];
  cout << "\nEnter an edge description: ";
  cin.get(desc,99,'\n');
  cin.ignore(1000,'\n');
  if(game->addEdge(curr,dest,desc)) cout << "\nEdge added from vertex " << curr << " to vertex " << dest;
  else cout << "\nFailed to add Edge"; 
}



