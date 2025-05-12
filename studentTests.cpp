#include "Graph.hpp"

int main()
{
    // set booleans to print true/false instead of 1/0 to improve readability
    cout << std::boolalpha << endl;


    // // test readFromSTDIN
    // // commented out for sake of the autograder
    cout << "construct gFile = readFromSTDIN();" << endl;
    // Graph gFile = Graph::readFromSTDIN();

    // Graph gFile(0);
    // gFile = gFile.readFromSTDIN();

    Graph gFile = Graph::readFromSTDIN();


    gFile.printVertices(); 
    gFile.printEdges();
    gFile.dijkstras(1111111111);
    // long u = 1211111111;
    // long v = 2222222222;
    // gFile.addEdge(u, v);
    // cout << "gFile.edgeIn for all possible edges: ";
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << endl;
    //     for (int n = 0; n < 6; n++)
    //     {
    //         // cout << "gFile.edgeIn(" << i << ", " << n << ") = " << g1.edgeIn(i, n) << endl;
    //         cout << "(" << i << ", " << n << ") = " << gFile.edgeIn(i, n) << ", ";
    //     }
    // }
    // cout << endl;

    return 0;

}