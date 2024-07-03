#include "priority_queue.hpp"

PriorityQueue::PriorityQueue() : heap_size(0) {
    for (int i = 0; i < MAXN; ++i) {
        pos[i] = -1;
    }
}

void PriorityQueue::push(int vertex, double vertex_cost) {
    if (pos[vertex] == -1) {
        heap[heap_size] = vertex;
        cost[heap_size] = vertex_cost;
        pos[vertex] = heap_size;
        heapify_up(heap_size);
        ++heap_size;
    } else {
        cost[pos[vertex]] = vertex_cost;
        heapify_up(pos[vertex]);
        heapify_down(pos[vertex]);
    }
}

int PriorityQueue::pop(double& vertex_cost) {
    int top_vertex = heap[0];
    vertex_cost = cost[0];
    pos[top_vertex] = -1;
    heap[0] = heap[--heap_size];
    if (heap_size > 0) {
        pos[heap[0]] = 0;
        heapify_down(0);
    }
    return top_vertex;
}

bool PriorityQueue::empty() {
    return heap_size == 0;
}

void PriorityQueue::swap(int i, int j) {
    int temp_vertex = heap[i];
    double temp_cost = cost[i];
    heap[i] = heap[j];
    cost[i] = cost[j];
    heap[j] = temp_vertex;
    cost[j] = temp_cost;
    pos[heap[i]] = i;
    pos[heap[j]] = j;
}

void PriorityQueue::heapify_up(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (cost[i] >= cost[parent])
            break;
        swap(i, parent);
        i = parent;
    }
}

void PriorityQueue::heapify_down(int i) {
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap_size && cost[left] < cost[smallest])
            smallest = left;
        if (right < heap_size && cost[right] < cost[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(i, smallest);
        i = smallest;
    }
}
