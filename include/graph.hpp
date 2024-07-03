#ifndef GRAPH_H
#define GRAPH_H
#define MAXN 1000
#include "edge.hpp"
#include <limits>

class GraphAdjList {
public:
    int n;
    Edge* adj_list[MAXN];

    GraphAdjList(int n);
    void add_edge(int from, int to, double weight, bool is_portal = false);
};

class GraphAdjMatrix {
public:
    int n;
    double **adj_matrix;
    bool **is_portal;

    GraphAdjMatrix(int n);
    void add_edge(int from, int to, double weight, bool portal = false);
};
#endif
