// Übungsblatt 10
// Aufgabe 1
// Stephan Aures


/*-----------------------------------------*/

// BFS

#include <iostream>
#include <list>

using namespace std;

class Graph 
{
    int numVertices;
    list<int>* adjLists;
    bool* visited;

    public:
    Graph(int vertices);
    void addEdgeBFS(int src, int dest);
    void addEdgeDFS(int src, int dest);
    void BFS(int startVertex);
    void DFS(int vertex);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];

    // for DFS
    visited = new bool[vertices];
}

// BFS add edges to the graph
void Graph::addEdgeBFS(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

// DFS add edges to the graph
void Graph::addEdgeDFS(int src, int dest)
{
    adjLists[src].push_front(dest);
}

// BFS algorithm
void Graph::BFS(int startVertex) 
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    visited[i] = false;

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited: " << currVertex << endl;
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) 
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

void Graph::DFS(int vertex)
{
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
        DFS(*i);
}

int main() 
{
    cout << "BFS:" << endl;

    Graph g(9);
    g.addEdgeBFS(0, 1);
    g.addEdgeBFS(0, 2);
    g.addEdgeBFS(0, 6);
    g.addEdgeBFS(1, 3);
    g.addEdgeBFS(2, 0);
    g.addEdgeBFS(2, 3);
    g.addEdgeBFS(2, 4);
    g.addEdgeBFS(3, 6);
    g.addEdgeBFS(4, 0);
    g.addEdgeBFS(4, 5);
    g.addEdgeBFS(4, 8);
    g.addEdgeBFS(5, 2);
    g.addEdgeBFS(5, 3);
    g.addEdgeBFS(5, 4);
    g.addEdgeBFS(5, 7);
    g.addEdgeBFS(6, 7);
    g.addEdgeBFS(7, 3);
    g.addEdgeBFS(7, 8);
    g.addEdgeBFS(8, 5);

    g.BFS(0);

    cout << endl << "DFS:" << endl;

    Graph g1(9);
    g1.addEdgeDFS(0, 1);
    g1.addEdgeDFS(0, 2);
    g1.addEdgeDFS(0, 6);
    g1.addEdgeDFS(1, 3);
    g1.addEdgeDFS(2, 0);
    g1.addEdgeDFS(2, 3);
    g1.addEdgeDFS(2, 4);
    g1.addEdgeDFS(3, 6);
    g1.addEdgeDFS(4, 0);
    g1.addEdgeDFS(4, 5);
    g1.addEdgeDFS(4, 8);
    g1.addEdgeDFS(5, 2);
    g1.addEdgeDFS(5, 3);
    g1.addEdgeDFS(5, 4);
    g1.addEdgeDFS(5, 7);
    g1.addEdgeDFS(6, 7);
    g1.addEdgeDFS(7, 3);
    g1.addEdgeDFS(7, 8);
    g1.addEdgeDFS(8, 5);

    g1.DFS(0);

    return 0;
}