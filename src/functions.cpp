#include "functions.hpp"
#include <limits>
#include "graph.hpp"
#define INF std::numeric_limits<double>::infinity()

double euclidean_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void initialize_array(double arr[], int size, double value) {
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
    }
}

void initialize_int_array(int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
    }
}

bool dijkstra(GraphAdjList& graph, int s, int q) {
    int n = graph.n;
    double dist[MAXN];
    int portals_used[MAXN];
    initialize_array(dist, n, INF);
    initialize_int_array(portals_used, n, 0);
    PriorityQueue pq;

    dist[0] = 0.0;
    pq.push(0, 0.0);

    while (!pq.empty()) {
        double d;
        int u = pq.pop(d);
        if (u == n - 1) return d <= s;

        for (Edge* edge = graph.adj_list[u]; edge != nullptr; edge = edge->next) {
            double new_dist = d + edge->weight;
            int new_portals_used = portals_used[u] + (edge->is_portal ? 1 : 0);

            if (new_portals_used <= q && new_dist < dist[edge->to]) {
                dist[edge->to] = new_dist;
                portals_used[edge->to] = new_portals_used;
                pq.push(edge->to, new_dist);
            }
        }
    }

    return false;
}

bool a_star(GraphAdjList& graph, double coordinates[MAXN][2], int s, int q) {
    int n = graph.n;
    double dist[MAXN];
    int portals_used[MAXN];
    initialize_array(dist, n, INF);
    initialize_int_array(portals_used, n, 0);
    PriorityQueue pq;

    dist[0] = 0.0;
    pq.push(0, euclidean_distance(coordinates[0][0], coordinates[0][1], coordinates[n - 1][0], coordinates[n - 1][1]));

    while (!pq.empty()) {
        double d;
        int u = pq.pop(d);
        if (u == n - 1) return dist[u] <= s;

        for (Edge* edge = graph.adj_list[u]; edge != nullptr; edge = edge->next) {
            double new_dist = dist[u] + edge->weight;
            int new_portals_used = portals_used[u] + (edge->is_portal ? 1 : 0);

            if (new_portals_used <= q && new_dist < dist[edge->to]) {
                dist[edge->to] = new_dist;
                portals_used[edge->to] = new_portals_used;
                double heuristic = euclidean_distance(coordinates[edge->to][0], coordinates[edge->to][1], coordinates[n - 1][0], coordinates[n - 1][1]);
                pq.push(edge->to, new_dist + heuristic);
            }
        }
    }

    return false;
}

bool dijkstra(GraphAdjMatrix& graph, int s, int q) {
    int n = graph.n;
    double dist[MAXN];
    int portals_used[MAXN];
    initialize_array(dist, n, INF);
    initialize_int_array(portals_used, n, 0);
    PriorityQueue pq;

    dist[0] = 0.0;
    pq.push(0, 0.0);

    while (!pq.empty()) {
        double d;
        int u = pq.pop(d);
        if (u == n - 1) return d <= s;

        for (int v = 0; v < n; ++v) {
            if (graph.adj_matrix[u][v] < INF) {
                double new_dist = d + graph.adj_matrix[u][v];
                int new_portals_used = portals_used[u] + (graph.is_portal[u][v] ? 1 : 0);

                if (new_portals_used <= q && new_dist < dist[v]) {
                    dist[v] = new_dist;
                    portals_used[v] = new_portals_used;
                    pq.push(v, new_dist);
                }
            }
        }
    }

    return false;
}

bool a_star(GraphAdjMatrix& graph, double coordinates[MAXN][2], int s, int q) {
    int n = graph.n;
    double dist[MAXN];
    int portals_used[MAXN];
    initialize_array(dist, n, INF);
    initialize_int_array(portals_used, n, 0);
    PriorityQueue pq;

    dist[0] = 0.0;
    pq.push(0, euclidean_distance(coordinates[0][0], coordinates[0][1], coordinates[n - 1][0], coordinates[n - 1][1]));

    while (!pq.empty()) {
        double d;
        int u = pq.pop(d);
        if (u == n - 1) return dist[u] <= s;

        for (int v = 0; v < n; ++v) {
            if (graph.adj_matrix[u][v] < INF) {
                double new_dist = dist[u] + graph.adj_matrix[u][v];
                int new_portals_used = portals_used[u] + (graph.is_portal[u][v] ? 1 : 0);

                if (new_portals_used <= q && new_dist < dist[v]) {
                    dist[v] = new_dist;
                    portals_used[v] = new_portals_used;
                    double heuristic = euclidean_distance(coordinates[v][0], coordinates[v][1], coordinates[n - 1][0], coordinates[n - 1][1]);
                    pq.push(v, new_dist + heuristic);
                }
            }
        }
    }

    return false;
}