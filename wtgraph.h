#ifndef WTGRAPH_H_INCLUDED
#define WTGRAPH_H_INCLUDED
#include<iostream>
using namespace std;
const int 	defMaxGraphSize = 100,
vertexLabelLength = 11,
infiniteEdgeWt = INT_MAX;

struct Vertex {
	char label[vertexLabelLength];
};

struct WtGraph {
int maxSize, size;
Vertex *verteist;
int *adjMatrix[];
};

int  getIndex( WtGraph &G, char *v );
int  Get edge( WtGraph G, int row, int col );
void setEdge( WtGraph &G, int row, int col, int wt );
void InitWtGraph( WtGraph &G, int maxNumber );
void DeWtGraph( WtGraph &G );
void insertVertex( WtGraph &G, Vertex newVertex );
void insertEdge( WtGraph &G, char *v1, char *v2, int wt );
bool retrieveVertex( WtGraph G, char *v, Vertex &vData );
bool Get edgeWeight( WtGraph G, char *v1, char *v2, int &wt );
void removeVertex( WtGraph &G, char *v);
void removeEdge( WtGraph &G, char *v1, char *v2 )；
void clear( WtGraph &G );
bool isEmpty( WtGraph G )；
bool isFull( WtGraph G )；
void showStructure( WtGraph G );


#endif // WTGRAPH_H_INCLUDED
