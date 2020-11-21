#include <iostream> 
#include <vector> 
#include <utility>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> ii;
typedef vector <ii> vii;

//Lista de adjacencias, vertice de origem, vertice final, peso da aresta
void addEdge(vector<vii> adj, int origin, int end, int cost){
    adj[origin].push_back( ii(end, cost) );
}

int main(void){
    int number_vertices, number_edges, origin, end, cost;
    vector<vii> adj_list;
    
    cout << "Digite o numero de vertices: ";
    cin >> number_vertices;
    
    cout << "Digite o numero de arestas: ";
    cin >> number_edges;
    
    adj_list.resize(number_vertices);
    
    cout << "Para montar as arestas, digite respectivamente:\n1 - Vertice de origem\n2 - Vertice final\n3 - Peso.\n\n";
    
    for(int i = 0; i < number_edges; i++){
        scanf("%d %d %d", &origin, &end, &cost);
        addEdge(adj_list, origin, end, cost);
    }
    
    return 0;
}