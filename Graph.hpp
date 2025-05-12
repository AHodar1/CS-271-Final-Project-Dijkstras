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

    // void printVertices();
    
    // void printEdges();
};

#include "Graph.tpp"