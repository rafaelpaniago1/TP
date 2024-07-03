#ifndef EDGE_H
#define EDGE_H

class Edge {
public:
    int to;
    double weight;
    bool is_portal;
    Edge* next;

    Edge(int to, double weight, bool is_portal);
};

#endif