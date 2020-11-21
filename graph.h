#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 
  
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
 
void printGraph(vector<int> adj[], int V) 
{ 
    for (int v = 0; v < V; ++v) 
    { 
        cout << "\n Adjacency list of vertex "
             << v << "\n head "; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        printf("\n"); 
    } 
} 
  
/*Exemplo de código main:

int main() 
{ 
    int V, number_edges;
    
    cout << "Digite o numero de vertices: ";
    
    cin >> V;
    
    vector<int> adj[V]; 
    
    cout << "Digite o numero de arestas: ";
    
    cin >> number_edges;
    
    int inicial_vertice, end_vertice;
    
    for(int i = 0; i < number_edges; ++i){
        cout << "Digite o vertice de entrada: ";
        cin >> inicial_vertice;
        cout << "Digite o vertice de saida: ";
        cin >> end_vertice;
        
        addEdge(adj, inicial_vertice, end_vertice);
    }
    
    printGraph(adj, V);
    
    Exemplo de grafo: 

    Vertices: 0, 1, 2, 3, 4;

    Arestas: (0, 1), (0, 4), (1, 2), (1, 3), (1, 4), (2, 3), (3, 4);

    printGraph(adj, V); 
    return 0; 
}*/