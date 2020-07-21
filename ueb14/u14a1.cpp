// Übungsblatt 14
// Aufgabe 1
// Stephan Aures


/*-----------------------------------------*/
#include <iostream>
using namespace std; 
  
#define V 6  
#define INF 99999  

void printSolution(int dist[][V]);  

void floydWarshall (int graph[][V])  
{  
    /* dist[][] will be the output matrix  
    that will finally have the shortest  
    distances between every pair of vertices */

    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    /* Add all vertices one by one to */
    for (k = 0; k < V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }
        printSolution(dist);  
    }
    cout << "Final solution:" << endl;
    printSolution(dist);  
}  

void printSolution(int dist[][V])  
{
    cout << "---------------------------" << endl;
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF || dist[i][j] > 90000)  
                cout << "INF" << "     ";  
            else
                cout << dist[i][j] << "     ";  
        }  
        cout << endl;  
    }
    cout << "---------------------------" << endl;  
}  

int main()  
{  
    int graph[V][V] = { {0, INF, INF, INF, -1, INF},  
                        {1 , 0 ,INF, 2, INF, INF},  
                        {INF, 2, 0, INF, INF, -8},  
                        {-4, INF, INF, 0, 3, INF},
                        {INF, 7, INF, INF, 0, INF},
                        {INF, 5, 10, INF, INF, 0}  
                      };  

    floydWarshall(graph);  
    return 0;  
}  