#include<iostream>
#include "MyDataStructures.h"
#define MAX 20
using namespace std;
//W - Not in Spanning Tree, B - Selected for Spanning Tree
enum MyColor {W,B};
struct Edge
{
int u,v; //Index of starting and terminating vertices
int Cost;
MyColor Color;
};
struct Vertex
{
int value;
int Set;
};
class Graph
{
Edge *E;
Vertex *V;
int nV,nE;
public:
//Initialize the size and the vertex' Indexs
Graph(int,int,int [][MAX]);
//weight matrix and starting vertex index is input
void Kruskals();
//bool ExtractMin(int &);
void SortEdges();
void ShowGraph();
};
void Graph::SortEdges()
{
Edge t;
for(int i=0;i<nE;i++)
{
    for(int j=i+1;j<nE;j++)
{
if(E[j].Cost<E[i].Cost)
{
t = E[j];
E[j] = E[i];
E[i] = t;
}
}
}
}
Graph::Graph(int e, int v, int w[][MAX])
{
nE = e;
nV = v;
E = new Edge[nE];
V = new Vertex[nV];
int k=0;
for(int i=0;i<nV;i++)
{
for(int j=0;j<i;j++)
{
if(w[i][j]!=0)
{
E[k].u = i;
E[k].v = j;
E[k].Cost = w[i][j];
E[k].Color = W;
k++;
}
}
V[i].value = i;
V[i].Set = i;
}
}
void Graph::ShowGraph()
{
for(int i=0;i<nE;i++)
{
if(E[i].Color==B)
{
cout<<"\n";
cout<<E[i].u<<"--"<<E[i].v<<" : Cost-"<<E[i].Cost;
}
}
}
void Graph::Kruskals()
{
    SortEdges();
int a,b;
for(int i=0;i<nE;i++)
{
if(V[E[i].u].Set!=V[E[i].v].Set)
{
E[i].Color = B;
a = V[E[i].u].Set;
b = V[E[i].v].Set;
for(int j=0;j<nV;j++)
{
if(V[j].Set == a)
V[j].Set = b;
}
}
}
}
int main()
{
int nV = 9;
int nE = 14;
int b[][MAX]={ {0,4,0,0,0,0,0,12,0},
{4,0,8,0,0,0,0,11,0},
{0,8,0,7,0,10,0,0,3},
{0,0,7,0,9,14,0,0,0},
{0,0,0,9,0,13,0,0,0},
{0,0,10,14,13,0,2,0,0},
{0,0,0,0,0,2,0,1,6},
{12,11,0,0,0,0,1,0,5},
{0,0,3,0,0,0,6,5,0}};
Graph g(nE,nV,b);
g.Kruskals();
g.ShowGraph();
}

