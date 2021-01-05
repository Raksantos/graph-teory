#include <utility>
#include <limits.h>
#include "operators.h"
#include "heap.h"
using namespace std;

int Heap::get_left(int i)
{
    return (i * 2);
}
int Heap::get_right(int i)
{
    return (i * 2) - 1;
}
int Heap::get_parent(int i)
{
    return i/2;
}

Heap::Heap()
{
    heap.push_back(ii(0, 0));      
    size = 0;
}

void Heap::push(ii x)
{
    size++;
    heap.resize(size + 1);
    heap[size] = x;
    int key = size;
    int parent = get_parent(key);

    while(parent >= 1 && (heap[key]) > (heap[parent]))
    {
        ii t = heap[key];
        heap[key] = heap[parent];
        heap[parent] = t;
        key = parent;
        parent = get_parent(key);
    }
}

ii Heap::top()
{
    return heap[1];
}

void Heap::max_heapify(int i){
    int largest, left, right;
    left = get_left(i);
    right = get_right(i);

    if(left <= size && heap[left] > heap[i]) largest = left;
    else largest = i;
    if(right <= size && heap[right] > heap[i]) largest = right;
    if(i != largest)
    {
        ii t = heap[i];
        heap[i] = heap[largest];
        heap[largest] = t;
        //swap(&heap[i], &heap[largest]);
        max_heapify(largest);
    }
}

bool Heap::empty()
{
    return size==0;
}

ii Heap::pop(){
    if(size > 0)
    {
        ii item = heap[1];
        heap[1] = heap[size];
        size--;
        heap.resize(size);
        max_heapify(1);
        return item;
    }

    return ii(INT_MIN, INT_MIN);
}

void Heap::Increase_Priority(int z, int w)
{
    for(int i = 1; i <= size; i++)
    {
        if(heap[i].first == z)
        {
            if(i != size)
            {
                heap[i] = heap[size];
                heap.resize(size);
                size--;
                this->max_heapify(i);
            }else{
                heap.resize(size);
                size--;
            }
            this->push(make_pair(z, w));
            break;
        }
    }
}

Heap make_pq(int cost[], Graph g)
{
    Heap h;
    for(int v = 0; v < g.V; v++) h.push(ii(v, cost[v]));

    return h;
}
