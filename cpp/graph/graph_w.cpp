#include<iostream>
#include<utility>
#include<vector>
#include<string>
#include<list>

using namespace std;

class Graph {
    private:
        int V;
        list<pair <int,int> > *adj;
    public:
        Graph(int V);
        void addedge(int V, int U, int w);
        void printGraph();
};

Graph::Graph(int V) 
{
    this->V = V;
    adj = new list<pair <int, int> >[V];
}

void Graph::addedge(int V, int U, int W) {
    adj[V].push_back(make_pair(U,W));
}

void Graph::printGraph() {
    for(int i=0; i<V; i++){
        string s = to_string(i) + "->";
        for(list<pair<int,int> >::iterator it = adj[i].begin(); it != adj[i].end(); ++it) {
            s = s + "(" + to_string(it->first) + "," + to_string(it->second) + ")" + "->";
        }
        cout<<s;
    }
}

int main() {
    Graph g(1);
    g.addedge(0, 1, 2);
    g.addedge(0, 2, 3);
    g.addedge(0, 4, 5);
    g.addedge(0, 6, 7);
    g.printGraph();
    return 0;
}


