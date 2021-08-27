#include<iostream>
#include "MyDataStructures.h"
#define MAX 20
using namespace std;
//W - Not Visited, B - Completely visited, including the adjacent nodes
enum MyColor {W,B};
struct Vertex
{
SList<int> AdjList; //To store the indices of vertex
int Value; //For easy understanding, the index will be stored as vertex value
MyColor Color; //Flag used to represent a vertex is visited or not
int Parent; //Index of the parent vertex in the resultant BFS tree
int Key; //Minimum cost from the curent vertex to the starting vertex
};
class Graph
{
Vertex *V;
int size;
public:
//Initialize the size and the vertex' Indexs
Graph(int);
//Adding an edge between two vertices. index of 'from' and 'to' given as input
//3rd arg - directed edge (true) or undirected edge (false)
void AddEdge(int,int);
//weight matrix and starting vertex index is input
void Prims(int [][MAX],int);
bool ExtractMin(int &);
void ShowGraph();
};
Graph::Graph(int n)
{
size = n;
V = new Vertex[n];
for(int i=0;i<n;i++)
{
V[i].Value = i;
V[i].Color = W;
V[i].Parent = -1;
V[i].Key = 9999;
}
}
bool Graph::ExtractMin(int &u)
{
int min;
min = 9999;
for(int i=0;i<size;i++)
{
if(V[i].Color==W && V[i].Key<min)
{
min = V[i].Key;
u = i;
}
}
if(min==9999)
return false;
else
return true;
}
void Graph::ShowGraph()
{
for(int i=0;i<size;i++)
{
cout<<"\n";
cout<<V[i].Parent<<"-->"<<V[i].Value;
}
}
void Graph::Prims(int w[][MAX],int r)
{
V[r].Key = 0;
V[r].Parent = -1;
int u;
int c;
while(ExtractMin(c))
{
for(int p=1;p<=V[c].AdjList.GetSize();p++)
{
if(V[c].AdjList.ElementAt(p,u))
{
if(V[u].Color==W && w[c][u]<V[u].Key)
{
V[u].Parent = c;
V[u].Key = w[c][u];
}
}
}
V[c].Color = B;
}
}
//from and to are the indices of nodes
void Graph::AddEdge(int from, int to)
{
V[from].AdjList.insertEnd(to);
}
int main()
{
int n=5;
Graph g(n);
int b[][MAX]={{0,4,1,2,0},
{4,0,0,8,6},
{1,0,0,7,0},
{2,8,7,0,5},
{0,6,0,5,0}};
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(b[i][j]!=0)
{
g.AddEdge(i,j);
}
}
}
g.Prims(b,0);
g.ShowGraph();
}
