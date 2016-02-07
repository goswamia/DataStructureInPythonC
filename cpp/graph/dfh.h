#include<iostream>
#include<list>

using namespace std;
class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited []);
    public:
    Graph(int V);
    void AddEdge(int V, int W);
    void DFS(int v);
};




