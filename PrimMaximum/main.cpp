#include <iostream>
#include "prim.h"

int main()
{

    //std::fstream myfile("C:\\Users\\Rodrigo\\Documents\\MyStuff\\UFAL\\teoria_dos_grafos\\PrimMaximum\\PrimMaximum.txt", std::ios_base::in);

    Graph g;
    int v0;
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


    // printf("Digite o numero de vertices do grafo: ");
    // scanf("%d", &g.V);

    // printf("Digite o numero de arestas do grafo: ");
    // scanf("%d", &g.E);

    // input quantidade de vertices, quantidade de arestas e vertice inicial
    scanf("%d %d %d", &g.V, &g.E, &v0);

    g.adj_list.resize(g.V);

    int vertex1, vertex2, weight;

    for(int i = 0; i < g.E; i++)
    {
        //printf("Digite, respectivamente, os vertices e o peso da aresta: ");
        scanf("%d%d%d", &vertex1, &vertex2, &weight);

        g.adj_list[vertex1].push_back(ii(vertex2, weight));
        g.adj_list[vertex2].push_back(ii(vertex1, weight));
    }

    int *t = prim(g, v0);

    for (int i = 0; i < g.V; i++) printf("%d pai: %d\n", i, t[i]);

    return 0;
}