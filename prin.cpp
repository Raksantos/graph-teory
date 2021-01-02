#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> pair_list;

struct graph{
    int V;
    int E;
    pair_list adj_list;
} typedef Graph;

class Heap{
    int getLeft(int i){
        return (i * 2);
    }

    int getRight(int i){
        return (i * 2) - 1;
    }
    int getParent(int i){
        return i/2;
    }

public:
    vii heap;
    int size;

    Heap(){
        heap.push_back(ii(0, 0));      
        size = 0;
    }

    void push(ii x){
        size++;
        heap.resize(size + 1);
        heap[size] = x;
        int key = size;
        int parent = getParent(key);

        while(parent >= 1 && (heap[key]) > (heap[parent])){
            ii t = heap[key];
            heap[key] = heap[parent];
            heap[parent] = t;
            key = parent;
            parent = getParent(key);
        }
    }

    ii top(){
        return heap[1];
    }
};

int main(){

    Graph g;

    printf("Digigte o numero de vertices do grafo: ");
    scanf("%d", &g.V);

    printf("Digite o numero de arestas do grafo: ");
    scanf("%d", &g.E);

    g.adj_list.resize(g.V);

    int vertex1, vertex2, weight;

    for(int i = 0; i < g.E; i++){
        printf("Digite, respectivamente, os vertices e o peso da aresta: ");
        scanf("%d%d%d", vertex1, vertex2, weight);

        g.adj_list[vertex1].push_back(ii(vertex2, weight));
        g.adj_list[vertex2].push_back(ii(vertex2, weight));
    }



    return 0;
}