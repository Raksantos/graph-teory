#include <utility>
#include <vector>

#ifndef GRAPH_H
#define GRAPH_H

typedef std::pair <int, int> ii;
typedef std::vector <ii> vii;
typedef std::vector <vii> pair_list;

struct graph
{
    int V;
    int E;
    pair_list adj_list;
} typedef Graph;

#endif /* GRAPH_H */