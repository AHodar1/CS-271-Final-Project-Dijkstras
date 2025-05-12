/*
Graph.hpp
Aurora hodar
5/8/25
Header file with definitions for creating weighted directed graphs
and running Dijkstra's Algorithm on them
*/

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
#include <fstream>

struct VertexData
{
    // should this be string?
    long id;
    std::pair<double, double> coords;
    double dist;
    long parent;
};

class Compare 
{
    public:
        bool operator()(VertexData a, VertexData b) const
        {
            return a.dist > b.dist;
        }
};



class Graph 
{
    private:
    // long = edge and double = weight
    std::vector<std::vector<std::tuple<long, double, std::string> > > adjList;
    std::map<long, std::pair<double, double>> idTracker;
    std::map<long, int> keyIndex;
    std::vector<long> indexKey;

    public:
    
    Graph(int n);

    Graph(const Graph &g);

    ~Graph(void);

    Graph& operator=(const Graph &g);

    int numEdges();

    void addEdge(long u, long v, double w, std::string name);

    void dijkstras(long s, long t);

    static Graph readFromSTDIN();
};

#include "Graph.tpp"