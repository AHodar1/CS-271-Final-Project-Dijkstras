#include "Graph.hpp"

int main()
{
    // set booleans to print true/false instead of 1/0 to improve readability
    cout << std::boolalpha << endl;

    // int g1Size = 4;
    // // test default constructor
    // cout << "construct g1(" << g1Size << ")" << endl;
    // Graph g1(g1Size);

    // // test vertexIn
    // for (int i = 0; i <= g1Size; i++)
    // {
    //     cout << "g1.vertexIn(" << i << ") = " << g1.vertexIn(i) << ", ";
    // }
    // cout << endl;

    // // test edgeIn
    // cout << "g1.edgeIn for all possible edges: ";
    // for (int i = 0; i < g1Size; i++)
    // {
    //     cout << endl;
    //     for (int n = 0; n < g1Size; n++)
    //     {
    //         cout << "(" << i << ", " << n << ") = " << g1.edgeIn(i, n) << ", ";
    //     }
    // }
    // cout << endl;

    // // test addEdge for two edges with same starting vertex and one different
    // cout << "g1.addEdge(0, 1), (0, 2), (3, 2);" << endl;
    // g1.addEdge(0, 1);
    // g1.addEdge(0, 2);
    // g1.addEdge(3, 2);
    // cout << "g1.edgeIn for all possible edges: ";
    // for (int i = 0; i < g1Size; i++)
    // {
    //     cout << endl;
    //     for (int n = 0; n < g1Size; n++)
    //     {
    //         cout << "(" << i << ", " << n << ") = " << g1.edgeIn(i, n) << ", ";
    //     }
    // }
    // cout << endl;
    
    // // test copy constructor
    // cout << "gCopy(g1);" << endl;
    // int gCopySize = g1Size;
    // Graph gCopy(g1);
    // cout << "gCopy.edgeIn for all possible edges: ";
    // for (int i = 0; i < gCopySize; i++)
    // {
    //     cout << endl;
    //     for (int n = 0; n < gCopySize; n++)
    //     {
    //         cout << "(" << i << ", " << n << ") = " << gCopy.edgeIn(i, n) << ", ";
    //     }
    // }
    // cout << endl;

    // // test removeEdge
    // cout << "g1.removeEdge(0, 2);" << endl;
    // g1.removeEdge(0, 2);
    // cout << "g1.edgeIn for all possible edges: ";
    // for (int i = 0; i < g1Size; i++)
    // {
    //     cout << endl;
    //     for (int n = 0; n < g1Size; n++)
    //     {
    //         cout << "(" << i << ", " << n << ") = " << g1.edgeIn(i, n) << ", ";
    //     }
    // }
    // cout << endl;

    // // ensure gCopy doesn't follow changes to g1
    // cout << "gCopy.edgeIn for all possible edges: ";
    // for (int i = 0; i < gCopySize; i++)
    // {
    //     cout << endl;
    //     for (int n = 0; n < gCopySize; n++)
    //     {
    //         cout << "(" << i << ", " << n << ") = " << gCopy.edgeIn(i, n) << ", ";
    //     }
    // }
    // cout << endl;
    
    // // see page 550 in textbook
    // int txtbookG_Size = 6;
    // cout << "construct txtbookG(" << txtbookG_Size << ") for testing DFS;" << endl;
    // Graph txtbookG(txtbookG_Size);
    // txtbookG.addEdge(0, 1);
    // txtbookG.addEdge(0, 3);
    // txtbookG.addEdge(3, 1);
    // txtbookG.addEdge(1, 4);
    // txtbookG.addEdge(4, 3);
    // txtbookG.addEdge(2, 4);
    // txtbookG.addEdge(2, 5);
    // txtbookG.addEdge(5, 5);
    // cout << "textbookG.edgeIn for all existing edges: ";
    // for (int i = 0; i < txtbookG_Size; i++)
    // {
    //     cout << endl;
    //     for (int n = 0; n < txtbookG_Size; n++)
    //     {
    //         if (txtbookG.edgeIn(i, n))
    //         {
    //             cout << "(" << i << ", " << n << ") = " << txtbookG.edgeIn(i, n) << ", ";
    //         }
    //     }
    // }
    // cout << endl;

    // // test readFromSTDIN
    // // commented out for sake of the autograder
    cout << "construct gFile = readFromSTDIN();" << endl;
    // Graph gFile = Graph::readFromSTDIN();

    Graph gFile(0);
    gFile = gFile.readFromSTDIN();
    gFile.printVertices();
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