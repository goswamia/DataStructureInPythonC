#include<iostream>
#include<list>
#include<string>
using namespace std;

class Graph {
    private:
        int V;
        list<int> *adj;
    public:
        Graph(int V);
        void addedge(int V, int W);
        void printGraph();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addedge(int v, int w) 
{
    adj[v].push_back(w);
}

void Graph::printGraph() {
    for(int i = 0; i<V; i++)
    {
        string s;
        for(list<int>::iterator it = adj[i].begin(); it != adj[i].end(); ++it)
        {
            s = s + "->" + to_string(*it); 

        }
        cout<<"list : "<<to_string(i)<<"->"<<s<<endl;
    }
}

int main() 
{
    Graph g(10);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(1, 4);
    g.addedge(2, 2);
    g.addedge(2, 2);
    g.addedge(3, 2);
    g.addedge(4, 2);
    g.addedge(5, 2);
    g.printGraph();
}
