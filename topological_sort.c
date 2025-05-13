#include <stdio.h>
#include <stdlib.h>

#define V 6

void DFS(int graph[V][V], int v, int visited[], int stack[], int *top) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(graph, i, visited, stack, top);
        }
    }
    stack[(*top)++] = v;
}

void topologicalSort(int graph[V][V]) {
    int visited[V] = {0};
    int stack[V];
    int top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    topologicalSort(graph);
    return 0;
}
