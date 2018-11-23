#include <iostream>
#include <cstring>
using namespace std;
/*INPUT: data.txt
 *
 * size of adj list '\n'
 * vertex:id|data:title|data:text|edge:targetId|endOfLine y/n char(see a)|'\n'
 * vertex:id|data:title|data:text|edge:targetId|endOfLine y/n char(see a)|'\n'
 *
 *
 * a) will keep reading line/creating new edges until 'x is read in
 */

//struct prototypes
struct Vertex;//need this so Edge doesn't flip out on definition of VERTEX before it exists
struct Edge;
//



struct Data{
  Data();
  ~Data();
  int disp();
  char * title;
  char * text;
};
struct Edge{
  Edge();
  ~Edge();
  int disp();
  struct Vertex *adj;
  //Vertex * adj;
  Edge * next;
  int targId;
};
struct Vertex{
  Vertex(Edge * tEdge, Data * tData);//upon creation, takes in an edge* and a data*
  ~Vertex();
  Data * data;//data will store all identifying info to be read out to the user
  struct Edge * head;
  //Edge * head;//Edge LLL
  int id;
};
class Game{
  public:
    Game(int size);
    ~Game();
    bool add(Vertex * tVert);
    int setEdges();
    int dispAll(int & size);
  private:
    int setEdges(Edge * & head);
    int dispEdges(Edge * head);
    Vertex ** adjList;
    int SIZE;
};
class Client{
  public:
    Client();
    ~Client();
    void populate();
    void dispAll();
  private:
    Game * game;
};

//utility
bool eolCheck(char x);
