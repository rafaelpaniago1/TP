#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define MAXN 1000

class PriorityQueue {
private:
    int heap[MAXN];
    double cost[MAXN];
    int pos[MAXN];
    int heap_size;

    void swap(int i, int j);
    void heapify_up(int i);
    void heapify_down(int i);

public:
    PriorityQueue();
    void push(int vertex, double vertex_cost);
    int pop(double& vertex_cost);
    bool empty();
};

#endif