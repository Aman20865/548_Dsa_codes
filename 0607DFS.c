#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10


void displayGraph(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    int i, j;
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}


void generateRandomGraph(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < numNodes; i++) {
        for (j = i; j < numNodes; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {

                double random = (double)rand() / RAND_MAX;


                graph[i][j] = (random <= 0.5) ? 1 : 0;
                graph[j][i] = graph[i][j];
            }
        }
    }
}
void DFS(int graph[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int current, int numNodes) {
    int i;
    visited[current] = 1;
    printf("%d ", current);

    for (i = 0; i < numNodes; i++) {
        if (graph[current][i] == 1 && visited[i] == 0) {
            DFS(graph, visited, i, numNodes);
        }
    }
}

int main() {
    int numNodes, i, j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numNodes);

    int graph[MAX_NODES][MAX_NODES];

    generateRandomGraph(graph, numNodes);

    printf("\nAdjacency Matrix:\n");
    displayGraph(graph, numNodes);

    int visited[MAX_NODES] = {0}; //

    printf("\nDFS Traversal: ");
    for (i = 0; i < numNodes; i++) {
        if (visited[i] == 0) {
            DFS(graph, visited, i, numNodes);
        }
    }

    return 0;
}

