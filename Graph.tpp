#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include "Graph.hpp"


using namespace std;

/*
default constructor
Purpose: Create an adjacency list with a size equal to the inputted # of vertices in graph
Parameters:
    -n, the # of vertices in graph and size of outer vector
Return Value:
    -N/A, but creates an empty adjancency list
Errors:
    -N/A
*/
Graph::Graph(int n)
{
    // assume vertices are 0...n-1;
    // adjList = std::vector<std::vector<Vertex>>(n);
    adjList = std::vector<std::vector<std::tuple<long, double, string>>>(n);    

}

/*
copy constructor
Purpose: Create an adjacency list with a size equal to g's adjacency list and fill out the adjacency list with each edge of g
Parameters:
    -g, the inputted graph to deep copy
Return Value:
    -N/A, but creates an adjancency list deep copy of g
Errors:
    -N/A
*/
Graph::Graph(const Graph &g)
{
    // adjList = std::vector<std::vector<int>>(g.adjList.size());
    // for (int i = 0; i < g.adjList.size(); i++)
    // {
    //     for (int n = 0; n < g.adjList[i].size(); n++)
    //     {
    //         addEdge(i, g.adjList[i][n]);
    //     }
    // }
}

/*
destructor (~Graph())
Purpose: cleans up any dynamic data and resets adjList
Parameters:
    -N/A
Return Value:
    -N/A, but clears adjList
Errors:
    -N/A
*/
Graph::~Graph(void)
{
    adjList.clear();
}

/*
assignment operator (operator=)
Purpose: Deep copy one graph onto another existing graph
Parameters:
    -g, the map to be copied
Return Value:
    -*this, a pointer to a deep copy of the inputted map
Errors:
    -N/A
*/
Graph &Graph::operator=(const Graph &g)
{
    // TODO: insert return statement here
    // adjList.clear();
    // adjList = std::vector<std::vector<int>>(g.adjList.size());
    // for (int i = 0; i < g.adjList.size(); i++)
    // {
    //     for (int n = 0; n < g.adjList[i].size(); n++)
    //     {
    //         // cout << "g1.edgeIn(" << i << ", " << n << ") = " << g1.edgeIn(i, n) << endl;
    //         // cout << "(" << i << ", " << n << ") = " << g1.edgeIn(i, n) << ", ";
    //         addEdge(i, g.adjList[i][n]);
    //     }
    // }
    return *this;

}

/*
addEdge
Purpose: Add an edge between the two inputted vertices
Parameters:
    -u, the first vertex the edge will lead from
    -v, the second vertex, which the edge will go to
Return Value:
    -void, but the adjacency list will have another value added to represent a new edge
Errors:
    -std::out_of_range, if either inputted vertex does not exist in the graph
    -also will do nothing if there is already an edge where attempting to add a new one
*/
void Graph::addEdge(long u, long v, double w, string streetName)
{
    cout << "test addEdge" << endl;
    if (idTracker.count(u) == 0)
    {
        throw std::out_of_range("addEdge: vertex/vertices do not exist");
    }
    else
    {
        std::tuple<long, double, string> vWname = std::make_tuple(v, w, streetName);
        adjList[keyIndex[u]].push_back(vWname);
    }

    // should maybe add this functionality back in?
    // if (!(edgeIn(u, v)))
    // {
    //     adjList[u].push_back(v);
    // }

}

/*
removeEdge
Purpose: Remove an edge between the two inputted vertices
Parameters:
    -u, the first vertex the edge to delete leads from
    -v, the second vertex, which the edge to delete goes to
Return Value:
    -void, but the adjacency list will have erased a value representing a former edge
Errors:
    -std::out_of_range, if either inputted vertex does not exist in the graph
    -std::out_of_range, if there is no edge between the two inputted vertices
*/
void Graph::removeEdge(int u, int v)
{
    // if (!(vertexIn(u)) || !(vertexIn(v)))
    // {
    //     throw std::out_of_range("removeEdge: vertex/vertices do not exist");
    // }
    // if (!(edgeIn(u, v)))
    // {
    //     throw std::out_of_range("removeEdge: inputted edge does not exist");
    // }
    
    // for (int i = 0; i < adjList[u].size(); i++)
    // {
    //     if (adjList[u][i] == v)
    //     {
    //         adjList[u].erase(adjList[u].begin() + i);
    //     }
    // }
}


/*
readFromSTDIN
Purpose: Read an inputted file of graph data and construct that graph
Parameters:
    -N/A, but there must be a text file read into studentTests
Return Value:
    -g, the newly constructed graph
Errors:
    -N/A
*/
Graph Graph::readFromSTDIN()
{
    int numVerts;
    int numEdges;
    cin >> numVerts >> numEdges;
    Graph g(numVerts);

    long vertID, u, v;
    double xCoord, yCoord, weight;
    string streetname;
    std::pair<double, double> coords;

    for (int i = 0; i < numVerts; i++)
    {
        cin >> vertID >> xCoord >> yCoord;
        coords = std::make_pair(xCoord, yCoord);
        g.idTracker.insert({vertID, coords});
        g.keyIndex.insert({vertID, i});
        g.indexKey.push_back(vertID);
    }
    for (int i = 0; i < numEdges; i++)
    {

        cin >> u >> v >> weight;
        getline(cin, streetname);
        // cout << "edge from vertex: " << u << " to vertex: " << v;
        // cout << " with weight: " << weight << " named: " << streetname << endl;
        g.addEdge(u, v, weight, streetname);
    }
    cout << g.idTracker.size() << endl;
    return g;
}

void Graph::printVertices()
{
    // for (auto iter = idTracker.begin(); iter != idTracker.end(); ++iter)
    for(auto kv : idTracker)
    {
        // cout << kv.first;
        cout << "id: " << kv.first << " xCoord = " << kv.second.first << " yCoord = " << kv.second.second << endl;
        
    }
}

void Graph::printEdges()
{
    long vert;
    double weight;
    string streetName;
    for(int i = 0; i < adjList.size(); i++)
    {
        // auto iter = keyIndex.begin();
        cout << "edge: " << indexKey[i] << endl;
        for (int n = 0; n < adjList[i].size(); n++)
        {
            tie(vert, weight, streetName) = adjList[i][n];
            cout << " to: " << vert << " with weight: " << weight;
            cout << ", (optional) named:" << streetName << endl;
            // cout << " to: " << adjList[i][n].first << " with weight: " << adjList[i][n].second << endl;
        } 
    }
}