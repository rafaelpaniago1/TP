#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "graph.hpp"
#include "priority_queue.hpp"
#include <math.h>

double euclidean_distance(double x1, double y1, double x2, double y2);
void initialize_array(double arr[], int size, double value);
void initialize_int_array(int arr[], int size, int value);
bool dijkstra(GraphAdjList& graph, double coordinates[MAXN][2], int s, int q);
bool dijkstra(GraphAdjMatrix& graph, double coordinates[MAXN][2], int s, int q);
bool a_star(GraphAdjList& graph, double coordinates[MAXN][2], int s, int q);
bool a_star(GraphAdjMatrix& graph, double coordinates[MAXN][2], int s, int q);

#endif