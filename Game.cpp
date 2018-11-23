#include "head.h"
//error highlighting = +++++

Game::Game(int size){
  SIZE = size;
  adjList = new Vertex *[SIZE];
}
Game::~Game(){
  delete adjList;
}
bool Game::add(Vertex * tVert){
  adjList[tVert->id] = tVert;
  return (tVert == adjList[tVert->id]) ? true : false;
}
int Game::setEdges(){
  int totalSet = 0;
  for(int i = 0; i < SIZE; ++i){
    totalSet += setEdges(adjList[i]->head);
  }
  return totalSet;
}
int Game::setEdges(Edge * & head){
  if(!head) return 0;
  int sumSet = 0;
  //cerr << "\n++++adj Vertex: " << adjList[head->targId]->data;
  head->adj = adjList[head->targId]; 
  return sumSet += setEdges(head->next);
}

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
int Game::dispEdges(Edge * head){
  if(!head) return 0;
  int sumEdg = 0;
  sumEdg += head->disp(); 
  return sumEdg += dispEdges(head->next);
}
