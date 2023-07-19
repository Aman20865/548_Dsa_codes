#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 10

void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void generateGraph(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    srand(time(NULL));
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = rand() % 2;
            }
        }
    }
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, int numVertices) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    printf("BFS traversal starting from vertex %d: ", startVertex);

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);


        for (int i = 0; i < numVertices; i++) {
            if (graph[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

int main() {

    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    generateGraph(graph, numVertices);
    displayGraph(graph, numVertices);

    int startVertex;+
    printf("Enter the starting vertex for BFS (0-%d): ", numVertices - 1);
    scanf("%d", &startVertex);

    bfs(graph, startVertex, numVertices);

    return 0;
}
