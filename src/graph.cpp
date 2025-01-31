#include "graph.hpp"
const double INF = 1e9;

GraphAdjList::GraphAdjList(int n) : n(n) {
    for (int i = 0; i < n; ++i) {
        adj_list[i] = nullptr;
    }
}

void GraphAdjList::add_edge(int from, int to, double weight, bool is_portal) {
    Edge* edge = new Edge(to, weight, is_portal);
    edge->next = adj_list[from];
    adj_list[from] = edge;
}

GraphAdjMatrix::GraphAdjMatrix(int n) : n(n) {
    adj_matrix = new double*[n];
    is_portal = new bool*[n];
    for (int i = 0; i < n; ++i) {
        adj_matrix[i] = new double[n];
        is_portal[i] = new bool[n];
        for (int j = 0; j < n; ++j) {
            adj_matrix[i][j] = 1e9;
            is_portal[i][j] = false;
        }
    }
}

void GraphAdjMatrix::add_edge(int from, int to, double weight, bool portal) {
    adj_matrix[from][to] = weight;
    is_portal[from][to] = portal;
}