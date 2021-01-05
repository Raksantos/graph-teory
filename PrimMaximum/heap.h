#include "graph.h"

class Heap
{
private:
    int get_left(int i);
    int get_right(int i);
    int get_parent(int i);

public:
    vii heap;
    int size;

    Heap();
    ii top();
    ii pop();
    bool empty();
    void push(ii x);
    void max_heapify(int i);
    void Increase_Priority(int z, int w);
};

Heap make_pq(int cost[], Graph g);
