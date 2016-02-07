#include<iostream>
#include "dfh.h"
using namespace std;


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::AddEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout<<v<<"  ";

    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++)
    {
        if(!visited[*i])
            DFSUtil(*i, visited);
    }
}

void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}

int main()
{
    Graph g(4);

    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(0,3);
    g.AddEdge(0,4);
    cout<<" Depth First Traversal"<<endl;
    g.DFS(2);
    return 0;
}

