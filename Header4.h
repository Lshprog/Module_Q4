#pragma once
namespace q4 {
    struct LinkedList {
        struct Node {
            int q;
            Node* next = nullptr;
            Node(int q);
        };
        Node* head = nullptr;
        Node* tail = nullptr;
        void add_node(int w);
    };
    class Graph
    {
        int v;
        LinkedList* adj;
        bool isCyclicUtil(int v, bool visited[], bool* rs);
    public:
        Graph(int v);
        void addEdge(int v, int w);
        bool isCyclic();
        void inputfunc(const char*);
    };
}
