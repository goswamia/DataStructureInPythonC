#include<iostream>
#include<list>
#include<string>

class Graph {
    private:
        std::list<int> *adj;
        int V;
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void BFS(int s);
        void printGraph();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int node) {

    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    std::list<int> queue;
    visited[node] = true;

    queue.push_back(node);

    while(!queue.empty()) {
        node  = queue.front();
        std::cout<<" : " <<node;
        queue.pop_front();
        for(std::list<int>::iterator i = adj[node].begin(); i != adj[node].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    std::cout<<std::endl;
}

void Graph::printGraph() {
    for (int i = 0; i<V; i++) {
        std::string s = std::to_string(i) + "->";
        for(std::list<int>::iterator j = adj[i].begin(); j !=adj[i].end(); ++j) {
            s = s + std::to_string(*j) + "->";
        }
        std::cout<<s<<std::endl;
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);
    g.printGraph();
}

