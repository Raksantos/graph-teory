#include <iostream>
#include "prim.h"

int main()
{
    Graph g;
    int v0;

    scanf("%d %d %d", &g.V, &g.E, &v0);

    g.adj_list.resize(g.V);

    int vertex1, vertex2, weight;

    for(int i = 0; i < g.E; i++)
    {
        scanf("%d%d%d", &vertex1, &vertex2, &weight);

        g.adj_list[vertex1].push_back(ii(vertex2, weight));
        g.adj_list[vertex2].push_back(ii(vertex1, weight));
    }

    int *t = prim(g, v0);

    for (int i = 0; i < g.V; i++) printf("%d pai: %d\n", i, t[i]);

    return 0;
}