#include <iostream>
#include <cmath>
#include "graph.hpp"
#include "priority_queue.hpp"
#include "functions.hpp"

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    double coordinates[n][2];
    for (int i = 0; i < n; ++i) {
        std::cin >> coordinates[i][0] >> coordinates[i][1];
    }

    GraphAdjList graph(n);
    GraphAdjMatrix graph2(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        double weight = euclidean_distance(coordinates[u][0], coordinates[u][1], coordinates[v][0], coordinates[v][1]);
        graph.add_edge(u, v, weight);
        graph2.add_edge(u,v,weight);
    }

    for (int i = 0; i < k; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph.add_edge(u, v, 0.0, true);
        graph2.add_edge(u, v, 0.0, true);
    }

    double s;
    int q;
    std::cin >> s >> q;

    bool dijkstra_result = dijkstra(graph, s, q);
    bool a_star_result = a_star(graph, coordinates, s, q);

    std::cout << (dijkstra_result ? 1 : 0) << " " << (a_star_result ? 1 : 0) << std::endl;

    return 0;
}