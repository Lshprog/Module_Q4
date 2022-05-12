#include "Header4.h"
#include <iostream>
#include <fstream>

std::ifstream F;

using namespace std;


q4::Graph::Graph(int v)
{
    this->v = v;
    adj = new LinkedList[v];
}

void q4::Graph::addEdge(int q, int w)
{
    adj[q].add_node(w);
}


bool q4::Graph::isCyclicUtil(int t, bool visited[], bool* recStack)
{
    if (visited[t] == false)
    {
        visited[t] = true;
        recStack[t] = true;

        LinkedList::Node* temp = adj[t].head;
        while (temp != nullptr)
        {
            if (!visited[temp->q] && isCyclicUtil(temp->q, visited, recStack))
                return true;
            else if (recStack[temp->q])
                return true;
            temp = temp->next;
        }

    }
    recStack[t] = false;
    return false;
}


bool q4::Graph::isCyclic()
{

    bool* visited = new bool[v];
    bool* recStack = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < v; i++)
        if (!visited[i] && isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}

void q4::Graph::inputfunc(const char* FILE_NAME) {
    F.open(FILE_NAME, std::ios::in);
    int size = 0;
    F >> size;
    int temp = 0;
    

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            F >> temp;
            if (temp == 1) {
                addEdge(i, j);
            }
        }
    }

    F.close();

};

void q4::LinkedList::add_node(int w)
{
    Node* temp = new Node(w);

    if (head == nullptr) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

q4::LinkedList::Node::Node(int q)
{
    this->q = q;
}
