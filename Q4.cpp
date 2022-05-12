#include <iostream>
#include <fstream>
#include "Header4.h";
const char FILE_NAME[] = "matrix.txt";
using namespace std;

int main()
{

    q4::Graph g(4);

    g.inputfunc(FILE_NAME);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;



}

