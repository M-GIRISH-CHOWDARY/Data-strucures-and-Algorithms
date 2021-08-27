#include<iostream>
#include"MYDataStructures.h"
using namespace std;

enum Mycolor{W,G,B};

struct vertex
{
    SList<int> adjlist;
    int value;
    Mycolor color;
    int dist;
    int parent;
};

class Graph
{
   vertex *v;
   int Size;

   public:
       Graph(int);
       void AddEdge(int,int);
       void BFS(int);
       void Display();
};

Graph::Graph(int n)
{
    Size=n;
    v=new vertex[n];
    for(int i=0;i<n;i++)
    { v[i].value=i;
      v[i].color=W;
      v[i].dist=9999;
      v[i].parent=-1;
    }
}

void Graph::Display()
{  for(int i=0;i<Size;i++)
   { if(v[i].parent!=-1)
       {
           cout<<"\n\t"<<v[i].parent<<"--->"<<v[i].value;
       }
     else{cout<<"\n\t"<<v[i].parent<<"--->"<<v[i].value;}
   }
}

void Graph::BFS(int i)
{
    v[i].color=W;
    v[i].parent=-1;
    v[i].dist=0;

    Queue<int> Q;
    Q.EnQ(i);
    int c,u;
    while(Q.DeQ(c))
    {  for(int p=1;p<=v[c].adjlist.GetSize();p++)
       {  if(v[c].adjlist.ElementAt(p,u))
          {
              if(v[u].color==W)
              {
                  v[u].color=G;
                  v[u].dist=v[c].dist+1;
                  v[u].parent=c;
                  Q.EnQ(u);
              }
          }
        }
      v[c].color=B;
    }
}

void Graph:: AddEdge(int from,int to)
{
    v[from].adjlist.insertEnd(to);
}

int main()
{
    Graph g(8);
    int b[][8]={{0,1,0,0,1,0,0,0},
                {1,0,0,0,0,1,0,0},
                {0,0,0,1,0,1,1,0},
                {0,0,1,0,0,0,1,1},
                {1,0,0,0,0,0,0,0},
                {0,1,1,0,0,0,1,0},
                {0,0,1,1,0,1,0,1},
                {0,0,0,1,0,0,1,0}};
     for(int i=0;i<8;i++)
     {
         for(int j=0;j<8;j++)
         {
             if(b[i][j]!=0)
             {
                 g.AddEdge(i,j);
             }
         }
     }
     g.BFS(1);
     g.Display();


}



















