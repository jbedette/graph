#include <iostream>
#include <cstring>
using namespace std;

//John Bedette, cs163, driected graph


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
//because Vertex and edge refer to each other
//they need to be pre defined as protypes before they
//can be initialized
struct Vertex;
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
  Edge * next;
  char * desc;
  int targId;
};

struct Vertex{
  Vertex(Edge * tEdge, Data * tData);//upon creation, takes in an edge* and a data*
  ~Vertex();
  Data * data;//data will store all identifying info to be read out to the user
  struct Edge * head;
  int id;
};


class Game{
  public:
    Game(int size);
    ~Game();
    bool add(Vertex * tVert);
    int setEdges();
    bool addEdge(int curr, int dest, char desc[]);
    int dispAll(int & size);
    int depth();
  private:
    int depthV(Vertex * v,Vertex *& out, int dest, bool vis[]);
    int depthE(Edge * head,Vertex *& out, int dest, bool vis[]);
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
    void addEdge();
    void traverse();
  private:
    Game * game;
};

//utility
bool eolCheck(char x);
