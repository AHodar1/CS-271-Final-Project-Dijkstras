#include "Graph.hpp"

int main()
{
    // set booleans to print true/false instead of 1/0 to improve readability
    cout << std::boolalpha << endl;

    cout << "construct gFile = readFromSTDIN();" << endl;

    // std::ifstream myfile ("easySampleData.out");
    // string fileText;
    // if (myfile.is_open()) 
    // { 
    //     cout << "files????" << endl;
    //     myfile >> fileText;
    //     cout << fileText;
    // }


    Graph gFile = Graph::readFromSTDIN();


 
    gFile.dijkstras(7234391442, 3531016709);
 
    return 0;

}