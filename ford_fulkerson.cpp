#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

struct graph
{
    int V;
    int E;
    vvi adj_list;
} typedef Graph;


bool bfs(Graph g, vvi residual, int begin, int end, int parent[])
{
    bool visited[g.V];
    memset(visited, false, sizeof(bool) * g.V);//setta todo o vetor de visitados como falso
    visited[begin] = true;
    queue<int> q;
    q.push(begin);

    int dequeued;

    while(!q.empty()){
        dequeued = q.front();
        q.pop();

        for(int i = 0; i < g.V; i++){
            if(residual[dequeued][i] > 0 && !visited[i]){
                parent[i] = dequeued;
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return visited[end];
}

int ford_fulkerson(Graph g, int begin, int end)
{
    int u, v, max_flow = 0;
    int *parent = new int[g.V];

    vvi residual;
    residual.resize(g.V);

    for(int i = 0; i < g.V; i++){
        residual[i].resize(g.V);
        for(int j = 0; j < g.V; j++){
            residual[i][j] = g.adj_list[i][j]; // atribui todos os pesos das arestas ao vertor residual
        }
    }

    while(bfs(g, residual, begin, end,parent)){
        int path = INT_MAX;

        for ( v = end; v != begin; v = parent[v]){
			u = parent[v];
			path = (residual[u][v] < path)? residual[u][v] : path;
		}

		for( v = end; v != begin; v = parent[v]){
			u = parent[v];
			residual[u][v] -= path;
			residual[v][u] += path;
		}
        max_flow += path;

    }

    return max_flow;
}

int main(){
    Graph g;
    int vertex1, vertex2, weight, begin, end;

    printf("Informe o numero de vertices do grafo: ");
    scanf("%d", &g.V);

    printf("Informe o numero de arestas do grafo: ");
    scanf("%d", &g.E);

    g.adj_list.resize(g.V);

    for (int i = 0; i < g.V; i++){
        g.adj_list[i].resize(g.V);
    }

    for (int i = 0; i < g.E; i++){

        printf("Informe o primeiro vertice, segundo vertice e peso da aresta: ");
        scanf("%d%d%d", &vertex1, &vertex2, &weight);

        g.adj_list[vertex1][vertex2] = weight;
    }

    printf("Informe o vertice inicial: ");
    scanf("%d", &begin);

    printf("Informe o vertice final: ");
    scanf("%d", &end);

    printf("O fluxo maximo desse grafo eh: %d", ford_fulkerson(g, begin, end));

    return 0;
}