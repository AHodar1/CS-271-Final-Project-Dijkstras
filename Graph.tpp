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
    adjList = std::vector<std::vector<int>>(n);    
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
    adjList = std::vector<std::vector<int>>(g.adjList.size());
    for (int i = 0; i < g.adjList.size(); i++)
    {
        for (int n = 0; n < g.adjList[i].size(); n++)
        {
            addEdge(i, g.adjList[i][n]);
        }
    }
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
    adjList.clear();
    adjList = std::vector<std::vector<int>>(g.adjList.size());
    for (int i = 0; i < g.adjList.size(); i++)
    {
        for (int n = 0; n < g.adjList[i].size(); n++)
        {
            // cout << "g1.edgeIn(" << i << ", " << n << ") = " << g1.edgeIn(i, n) << endl;
            // cout << "(" << i << ", " << n << ") = " << g1.edgeIn(i, n) << ", ";
            addEdge(i, g.adjList[i][n]);
        }
    }
    return *this;

}

/*
dfsVisit
Purpose: Helper function for depthFirstSearch
    Assigns attributes to each member of data and recursively find neighbors of the current vertex
Parameters:
    -data, a reference to the vector of TraversalData created in depthFirstSearch
    -time, a references to the variable tracking time of discovery and finish times of each vertex
    -u, the current vertex being discovered and altered
    -order, a reference to the variable tracking topological ordering of each vertex as they finish
Return Value:
    -void, but alters and assigns attributes for connected vertices of the graph in data
Errors:
    -N/A
*/
void Graph::dfsVisit(std::vector<TraversalData> &data, int &time, int u, int &order)
{
    time++;
    data[u].visited = true;
    data[u].discovery = time;
    for (int v = 0; v < adjList[u].size(); v++)
    {
        if (data[adjList[u][v]].visited == false)
        {
            data[adjList[u][v]].parent = u;
            dfsVisit(data, time, adjList[u][v], order);
        }
    }
    time++;
    data[u].finish = time;
    data[u].order = order;
    order--;
}

/*
vertexIn
Purpose: Check if the inputted vertex is in the graph 
Parameters:
    -u, the vertex to check for
Return Value:
    -vertexInGraph, a bool to check if vertex is in graph
Errors:
    -N/A
*/
bool Graph::vertexIn(int u)
{
    bool vertexInGraph = false;
    if (u < adjList.size())
    {
        vertexInGraph = true;
    }
    return vertexInGraph;
}

/*
edgeIn
Purpose: Check for an edge between the two inputted vertices in graph 
Parameters:
    -u, the first vertex the edge would lead from
    -v, the second vertex, which the edge would go to
Return Value:
    -edgeInGraph, a bool to check if the wanted edge is in graph
Errors:
    -std::out_of_range, if either inputted vertex does not exist in the graph
*/
bool Graph::edgeIn(int u, int v)
{
    if (!(vertexIn(u)) || !(vertexIn(v)))
    {
        throw std::out_of_range("edgeIn: vertex/vertices do not exist");
    }

    bool edgeInGraph = false;
    for (int i = 0; i < adjList[u].size(); i++)
    {
        if (adjList[u][i] == v)
        {
            edgeInGraph = true;
        }
    }
    return edgeInGraph;
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
void Graph::addEdge(int u, int v)
{
    if (!(vertexIn(u)) || !(vertexIn(v)))
    {
        throw std::out_of_range("addEdge: vertex/vertices do not exist");
    }
    
    if (!(edgeIn(u, v)))
    {
        adjList[u].push_back(v);
    }

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
    if (!(vertexIn(u)) || !(vertexIn(v)))
    {
        throw std::out_of_range("removeEdge: vertex/vertices do not exist");
    }
    if (!(edgeIn(u, v)))
    {
        throw std::out_of_range("removeEdge: inputted edge does not exist");
    }
    
    for (int i = 0; i < adjList[u].size(); i++)
    {
        if (adjList[u][i] == v)
        {
            adjList[u].erase(adjList[u].begin() + i);
        }
    }
}

/*
breadthFirstSearch
Purpose: Make a vector of attributes for each vertex in the graph representing the results of a breadth-first-search
Parameters:
    -s, the source vertex to start a breadth first search from
Return Value:
    -bfs, a vector of TraversalData representing bfs attributes for each vertex of the graph
Errors:
    -std::out_of_range, if the inputted vertex does not exist in the graph
*/
std::vector<TraversalData> Graph::breadthFirstSearch(int s)
{
    std::vector<TraversalData> bfs(adjList.size());
    if (!(vertexIn(s)))
    {
        throw std::out_of_range("breadthFirstSearch: vertex not in graph");
    }
    else
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            bfs[i].visited = false;
            // -1 = NIL
            bfs[i].parent = -1;
            // INT_MAX = infinity
            bfs[i].distance = __INT_MAX__;
        }
        bfs[s].visited = true;
        bfs[s].distance = 0;
        std::deque<int> toVisit;
        toVisit.push_back(s);
        while (!(toVisit.empty()))
        {
            int u = toVisit.front();
            toVisit.pop_front();
            for (int v = 0; v < adjList[u].size(); v++)
            {
                if (bfs[adjList[u][v]].visited == false)
                {
                    bfs[adjList[u][v]].visited = true;
                    bfs[adjList[u][v]].distance = bfs[u].distance + 1;
                    bfs[adjList[u][v]].parent = u;
                    toVisit.push_back(v);
                }
            }
        }
    }
    return bfs;
}

/*
depthFirstSearch
Purpose: 
Parameters:
    -N/A
Return Value:
    -dfs, a vector of TraversalData representing dfs attributes for each vertex of the graph
Errors:
    -N/A
*/
std::vector<TraversalData> Graph::depthFirstSearch(void)
{
    std::vector<TraversalData> dfs(adjList.size());
    int time = 0;
    int order = dfs.size();
    for (int i = 0; i < adjList.size(); i++)
    {
        dfs[i].visited = false;
        // -1 = NIL
        dfs[i].parent = -1;
        // dfs[i].order = 0;
    }
    for (int i = 0; i < adjList.size(); i++)
    {
        if (dfs[i].visited == false)
        {
            dfsVisit(dfs, time, i, order);

        }
    }

    return dfs;
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
    int size;
    int numEdges;
    cin >> size >> numEdges;
    Graph g(size);

    int u;
    int v;

    for (int i = 0; i < numEdges; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    return g;
}
