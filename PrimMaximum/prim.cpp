#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> pair_list;

struct graph
{
    int V;
    int E;
    pair_list adj_list;
} typedef Graph;

bool operator< (ii a, ii b){
	return (a.second)<(b.second);
}
bool operator>=(ii a,ii b){
	return(a.second)>=(b.second);
}
bool operator>(ii a ,ii b){
	return (a.second)>(b.second);
}
bool operator<=(ii a, ii b){
	return (a.second)<=(b.second);
}
bool operator==(ii a ,ii b){
	return (a.second)==(b.second);
}
bool operator!=(ii a,ii b){
	return (a.second)!=(b.second);
}

class Heap
{
    int get_left(int i)
    {
        return (i * 2);
    }
    int get_right(int i)
    {
        return (i * 2) - 1;
    }
    int get_parent(int i)
    {
        return i/2;
    }

public:
    vii heap;
    int size;

    Heap()
    {
        heap.push_back(ii(0, 0));      
        size = 0;
    }

    void push(ii x)
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

    ii top()
    {
        return heap[1];
    }

    void max_heapify(int i){
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

    bool empty()
    {
        return size==0;
    }

    ii pop(){
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

    void Increase_Priority(int z, int w)
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
};

Heap make_pq(int cost[], Graph g)
{
    Heap h;
    for(int v = 0; v < g.V; v++) h.push(ii(v, cost[v]));

    return h;
}

int *prim(Graph g, int v0)
{
    int cost[g.V], *prev = new int[g.V];

    bool mstSet[g.V];

    for(int u = 0; u < g.V; u++)
    {
        cost[u] = INT_MIN;
        prev[u]  = -1;
        mstSet[u] = false;
    }

    cost[v0] = 0;
    mstSet[v0] = true;

    Heap H = make_pq(cost, g);
    while(!H.empty())
    {
        int v = H.top().first;
        mstSet[v] = true;
        H.pop();

        for(auto z : g.adj_list[v])
        {
            if(cost[z.first] < z.second && !mstSet[z.first])
            {
                cost[z.first] = z.second;
                H.Increase_Priority(z.first, cost[z.first]);
                prev[z.first] = v;
            }
        }
    }

    return prev;
}

int main()
{

    //std::fstream myfile("C:\\Users\\Rodrigo\\Documents\\MyStuff\\UFAL\\teoria_dos_grafos\\PrimMaximum\\PrimMaximum.txt", std::ios_base::in);

    Graph g;

    // int a, b, c;

    // int vertex1, vertex2, weight;

    // while(myfile >> a >> b >> c)
    // {
    //     g.V = a;
    //     g.E = b;
        
    //     for(int i = 0; i < g.E; i++)
    //     {
    //         vertex1 = c;
    //         vertex2 = c;
    //         weight = c;

    //         g.adj_list[vertex1].push_back(ii(vertex2, weight));
    //         g.adj_list[vertex2].push_back(ii(vertex1, weight));
    //     }
    // }


    printf("Digite o numero de vertices do grafo: ");
    scanf("%d", &g.V);

    printf("Digite o numero de arestas do grafo: ");
    scanf("%d", &g.E);

    g.adj_list.resize(g.V);

    int vertex1, vertex2, weight;

    for(int i = 0; i < g.E; i++)
    {
        printf("Digite, respectivamente, os vertices e o peso da aresta: ");
        scanf("%d%d%d", &vertex1, &vertex2, &weight);

        g.adj_list[vertex1].push_back(ii(vertex2, weight));
        g.adj_list[vertex2].push_back(ii(vertex1, weight));
    }

    int *t = prim(g, 0);

    for (int i = 0; i < g.V; i++) printf("%d pai: %d\n", i, t[i]);

    return 0;
}