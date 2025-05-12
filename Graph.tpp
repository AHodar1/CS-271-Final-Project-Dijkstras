/*
Graph.tpp
Aurora hodar
5/8/25
Implementations for creating weighted directed graphs
and running Dijkstra's Algorithm on them
*/

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
    adjList = std::vector<std::vector<std::tuple<long, double, string>>>(n);    

}

/*
copy constructor
Purpose: Create an adjacency list and other trackers deep copied from g
Parameters:
    -g, the inputted graph to deep copy
Return Value:
    -N/A, but creates an adjancency list deep copy of g
Errors:
    -N/A
*/
Graph::Graph(const Graph &g)
{
    adjList = std::vector<std::vector<std::tuple<long, double, string>>>(g.adjList.size());
    long IDv;
    double weight;
    string streetName;
    for (int i = 0; i < g.adjList.size(); i++)
    {
        for (int n = 0; n < g.adjList[i].size(); n++)
        {

            tie(IDv, weight, streetName) = g.adjList[i][n];
            addEdge(indexKey[i], IDv, weight, streetName);
        }
    }
    for (auto kv : g.idTracker)
    {
        idTracker.insert({kv.first, kv.second});
    }
    for (auto kv : g.keyIndex)
    {
        keyIndex.insert({kv.first, kv.second});
    }
    for (int i = 0; i < g.indexKey.size(); i++)
    {
        indexKey[i] = g.indexKey[i];
    }
}

/*
destructor (~Graph())
Purpose: cleans up any dynamic data and resets adjList, idTracker, keyIndex, and indexKey
Parameters:
    -N/A
Return Value:
    -N/A, but clears adjList, idTracker, keyIndex, and indexKey
Errors:
    -N/A
*/
Graph::~Graph(void)
{
    adjList.clear();
    idTracker.clear();
    keyIndex.clear();
    indexKey.clear();
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
    adjList.clear();
    idTracker.clear();
    keyIndex.clear();
    indexKey.clear();
    adjList = std::vector<std::vector<std::tuple<long, double, string>>>(g.adjList.size());
    long IDv;
    double weight;
    string streetName;
    for (int i = 0; i < g.adjList.size(); i++)
    {
        for (int n = 0; n < g.adjList[i].size(); n++)
        {

            tie(IDv, weight, streetName) = g.adjList[i][n];
            addEdge(indexKey[i], IDv, weight, streetName);
        }
    }
    for (auto kv : g.idTracker)
    {
        idTracker.insert({kv.first, kv.second});
    }
    for (auto kv : g.keyIndex)
    {
        keyIndex.insert({kv.first, kv.second});
    }
    for (int i = 0; i < g.indexKey.size(); i++)
    {
        indexKey[i] = g.indexKey[i];
    }
    return *this;

}

/*
numEdges
Purpose: Easy way to keep track of how many edges are in the graph
Parameters: 
    -N/A
Return Value:
    -count, the number of edges in the graph
Errors:
    -N/A*/
int Graph::numEdges()
{
    int count = 0;
    for (int i = 0; i < adjList.size(); i++)
    {
        for (int n = 0; n < adjList[i].size(); n++)
        {
            count++;
        }
    }
    cout << count << endl;
    return count;
}

/*
addEdge
Purpose: Add an edge between the two inputted vertices to adjList, along
    with the edge weight and street name
Parameters:
    -u, the first vertex the edge will lead from
    -v, the second vertex, which the edge will go to
    -w, the weight of the edge 
    -streetName, the name of the street, if there is one
Return Value:
    -void, but the adjacency list will have another value added to represent a new edge
Errors:
    -std::out_of_range, if either inputted vertex does not exist in the graph=
*/
void Graph::addEdge(long u, long v, double w, string streetName)
{
    if (idTracker.count(u) == 0)
    {
        throw std::out_of_range("addEdge: vertex/vertices do not exist");
    }
    else
    {
        std::tuple<long, double, string> vWname = std::make_tuple(v, w, streetName);
        adjList[keyIndex[u]].push_back(vWname);
    }
}
/*
dijkstras
Purpose: Find the shortest path between two inputted vertices
Parameter:
Returns:
    -N/A, but prints out values for the path taken
Errors:
    -N/A*/
void Graph::dijkstras(long s, long t)
{

    std::priority_queue <VertexData, std::vector<VertexData>, Compare> Q;
    std::vector<VertexData> S;
    
    for (auto iter : idTracker)
    {
        VertexData vert;
        vert.id = iter.first;
        vert.coords = iter.second;
        if (vert.id == s)
        {
            vert.dist = 0;
        }
        else
        {
            vert.dist = INT_MAX;
        }
        vert.parent = -1;
        Q.push(vert);
    }
    
    while (!(Q.empty()))
    {
        VertexData u = Q.top();
        Q.pop();
        bool visited = false;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i].id == u.id)
            {
                visited = true;
            }
        }
        long IDv;
        double weight;
        string streetName;
        if (!(visited))
        {
            S.push_back(u);
            for (int i = 0; i < adjList[keyIndex[u.id]].size(); i++)
            {
                tie(IDv, weight, streetName) = adjList[keyIndex[u.id]][i];
                VertexData v;
                v.id = IDv;
                v.coords = idTracker[IDv];
                v.dist = u.dist + weight;
                v.parent = u.id;
                Q.push(v);
            }
        }
    }
    long curParent;
    double finalDist;
    for (int i = 0; i < S.size(); i++)
    {
        if(S[i].id == t)
        {
            curParent = S[i].id;
            finalDist = S[i].dist;
        }
    }
    std::vector<long> parentChain;
    while (curParent != -1)
    {
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i].id == curParent)
            {
                parentChain.insert(parentChain.begin(), curParent);
                curParent = S[i].parent;
            }   
        }
    }
    string path = "The shortest path from (" + to_string(idTracker[s].first);
    path = path + "m " + to_string(idTracker[s].second) + ") to (";
    path = path + to_string(idTracker[t].first) + ", " + to_string(idTracker[t].second) + ") is \n";

    for (int i = 0; i < parentChain.size(); i++)
    {
        path = path + "(" + to_string(idTracker[parentChain[i]].first) + ", " + to_string(idTracker[parentChain[i]].second) + ")\n";

    }
    path = path + "and it has weight " + to_string(finalDist) + ".\n";
    cout << path << endl;
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
        g.addEdge(u, v, weight, streetname);
    }
    // cout << g.idTracker.size() << endl;
    return g;
}