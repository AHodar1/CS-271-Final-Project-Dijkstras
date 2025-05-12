#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include <climits>


struct TraversalData {
    bool visited;
    int parent;
    union {
        struct {
            int discovery;
            int finish;
            int order;
        };
        struct {
            int distance;
        };
    };
};

struct DijkstraData
{

};

struct VertexData
{
    // should this be string?
    long id;
    // std::make_pair(n, a[1])
    std::pair<double, double> coords;
    // Dijkstra's values
    int dist;
    long parent;
};

struct EdgeData
{
    long u, v;
    double weight;
    std::string streetName;

};

class Compare 
{
    public:
        bool operator()(VertexData a, VertexData b) const
       {
            // long a_IDv, b_IDv;
            // double a_weight, b_weight;
            // std::string a_streetName, b_streetName;
            // tie(a_IDv, a_weight, a_streetName) = a;
            // tie(b_IDv, b_weight, b_streetName) = b;

            return a.dist > b.dist;
            //    if(a->getFreq() > b->getFreq())
            //    {
            //        return true;
            //    }
            // return false;
        }
};



class Graph {
    private:
    // long = edge and double = weight
    std::vector<std::vector<std::tuple<long, double, std::string> > > adjList; // adjacency list
    // std::vector<std::vector<Edge> > adjList; // adjacency list
    
    
    // std::unordered_map<long, std::pair<double, double>> idTracker;
    std::map<long, std::pair<double, double>> idTracker;
    std::map<long, int> keyIndex;
    std::vector<long> indexKey;
    
    
    // std::unordered_map<long, index>
    // order is a variable used to keep track of the position of the last element placed in the topological ordering
    void dfsVisit(std::vector<TraversalData> &data, int &time, int u, int &order);

    public:
    

    Graph(int n);

    Graph(const Graph &g);

    ~Graph(void);

    Graph& operator=(const Graph &g);

    // return true if u is in the graph, false otherwise
    // bool vertexIn(int u);

    // throw an std::out_of_range exception if u or v is not in the graph
    // bool edgeIn(int u, int v);

    int numEdges();

    void addEdge(long u, long v, double w, std::string name);

    // throw an std::out_of_range exception if u or v is not in the graph
    // throw an std::out_of_range exception if (u, v) is not an edge of the graph
    void removeEdge(int u, int v);

    void dijkstras(long s);

    static Graph readFromSTDIN();

    void printVertices();
    
    void printEdges();
};

#include "Graph.tpp"