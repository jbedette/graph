#include "head.h"

//John Bedette, cs163, driected graph
//Game contains all logic not involved with reading in data



//upon creation, takes in size of array of vertexes
Game::Game(int size){
  SIZE = size;
  adjList = new Vertex *[SIZE];
}


//calls delete on each Vertex, then deletes list
Game::~Game(){
  for(int i = 0; i < SIZE; ++i){
    delete adjList[i];
  }
  delete adjList;
}



//New Vertices come in with an id already assigned
//they are inserted into the vertex array at their index
//if the assignment is successful, the function returns true
bool Game::add(Vertex * tVert){
  adjList[tVert->id] = tVert;
  return (tVert == adjList[tVert->id]) ? true : false;
}



//Set edges is called after the Vertices are all assigned
//moves through Vertex array and calls
//a recursive function that traverses edges and links adj pointers  
//returns total number of edges assigned
int Game::setEdges(){
  int totalSet = -1;
  for(int i = 0; i < SIZE; ++i){
    totalSet += setEdges(adjList[i]->head);
  }
  return totalSet;
}



//when an edge is created, a target Vertex's id is assigned to it
//if the edge is supposed to point to something and is not a dead
//end, it's targeted Vertex's id will be > -1
//returns the number of edges assigned
int Game::setEdges(Edge * & head){
  if(!head) return 0;
  int sumSet = 0;
  if(head->targId >= 0)head->adj = adjList[head->targId]; 
  return sumSet += setEdges(head->next) + 1;
}



//displays all Vertices, their data, all their edges,
//and some info from each adjacent Vertex
//returns total Edges and assigns passed in 'int&' to
//total number of Vertices
int Game::dispAll(int & size){
  int total = 0;//total edges
  for(int i = 0; i < SIZE; ++i){
    if(adjList[i]){;
      size += adjList[i]->data->disp();
      total += dispEdges(adjList[i]->head);
    }else{//testing
      cerr << "\n+++++wtf something is empty at: adjList[" << i << "]\n";
    }
  }
  return total;
}



//Recurses through edge list and displays all edges
int Game::dispEdges(Edge * head){
  if(!head) return 0;
  int sumEdg = 0;
  sumEdg += head->disp(); 
  return sumEdg += dispEdges(head->next);
}



/*
int Game::traverse(){
  return traverse(adjList[0]);
}
int Game::traverse(Vertex *& v){
  if(!v)return 0;
  int count = 0;
  int edgecount = dispEdges(head);
  return count;
}
*/


//Depth wrappper makes an array of bools directly related to
//the size of the array of vertices,sets it all to null
//passes in a vertex pointer to prove that depth search worked
//by getting the correct data out
int Game::depth(){
  bool visited[SIZE];
  for(int i = 0; i < SIZE; ++i){
    visited[i] = false;
  }
  Vertex * out = NULL;
  depthV(adjList[0], out, SIZE-1, visited);
  return out->id;
}



//depth vertex recursive, takes in a vertex, if correct, 
//assigns output vertex, if false flips visited bool and 
//recurses down the edge list
int Game::depthV(Vertex * v, Vertex *& out, int dest, bool vis[]){
  if(v->id == dest){
    out = v;
    return v->id;
  }
  vis[v->id] = true; 
  return depthE(v->head,out,dest,vis);
}



//depth edge recursive
//if the edge target is -1 or the edge is null, return
//else establish stack of edges to test
int Game::depthE(Edge * head, Vertex *& out, int dest, bool vis[]){
  if(!head || head->targId < 0) return 0;
  if(!vis[head->targId]) depthV(head->adj,out,dest, vis);
  return depthE(head->next,out,dest,vis);
}



//addEdge will insert a new edge at the beginning of the Edge LLL 
//if the Edge Node has a null adj * to signify a dead end
//the Edge's data will be assigned to the new desired adj vertex
//it takes in an int curr represent where to add the Edge
//and an int dest to tell it where to point
bool Game::addEdge(int curr, int dest, char desc[]){
  if(adjList[curr]->head && adjList[curr]->head->adj){
    Edge * temp = adjList[curr]->head;
    adjList[curr]->head = new Edge;
    adjList[curr]->head->next = temp;
  }
  adjList[curr]->head->desc = new char[strlen(desc)+1];
  strcpy(adjList[curr]->head->desc,desc);
  adjList[curr]->head->targId = dest;
  adjList[curr]->head->adj = adjList[dest];
  return (adjList[curr]->head->adj->id == dest) ? true : false;
}



