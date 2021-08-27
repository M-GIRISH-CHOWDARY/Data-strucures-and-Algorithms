#include<iostream>
#include"MyDataStructures.h"
using namespace std;

enum Mycolor{W,G,B};

struct vertex
{
    SList<int> adjlist;
    int value;
    Mycolor color;
    int s,f;
    int parent;
};

class Graph
{
   vertex *v;
   int Size;
   public:
   Graph(int);
   void AddEdge(int from,int to);
   void DFS_visit(int r,int &time);
   void DFS( );
   void Display();
};

Graph::Graph(int n)
{
    Size=n;
    v=new vertex[n];
    for(int i=0;i<n;i++)
    { v[i].value=i;
      v[i].color=W;

      v[i].parent=-1;
    }
}

void Graph::Display()
{  for(int i=0;i<Size;i++)
   {

           cout<<"\n\t"<<"start time="<<v[i].s<<"     finish time="<<v[i].f ;
           cout<<"   "<<v[i].parent<<"--->"<<v[i].value;


   }
}

void Graph:: DFS()
{ int time;
  time=0;
  for(int i=0;i<Size;i++)
    {
        if(v[i].color==W)
        {
            DFS_visit(i,time);
        }
    }
}

void Graph::DFS_visit(int r,int &time)
{
    int u;
    time++;
    v[r].s=time;
    v[r].color=G;
    for(int p=0;p<=v[r].adjlist.GetSize();p++)
    {
        if(v[r].adjlist.ElementAt(p,u))
        {
            if(v[u].color==W)
            {
                v[u].parent=r;
                DFS_visit(u,time);
            }
        }
    }
    time++;
    v[r].f=time;
    v[r].color=B;
}

void Graph:: AddEdge(int from,int to)
{
    v[from].adjlist.insertEnd(to);
}


int main()
{
    Graph g(6);
    int b[][6]={{0,1,0,1,0,0},
                {0,0,0,0,4,0},
                {0,0,0,0,1,1},
                {0,1,0,0,0,0},
                {0,0,0,1,0,0},
                {0,0,0,0,0,0}};
     for(int i=0;i<6;i++)
     {
         for(int j=0;j<6;j++)
         {
             if(b[i][j]!=0)
             {
                 g.AddEdge(i,j);
             }
         }
     }
     g.DFS( );
     g.Display();

}













 
