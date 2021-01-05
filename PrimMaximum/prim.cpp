#include <limits.h>
#include "heap.h"
#include "prim.h"
using namespace std;

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