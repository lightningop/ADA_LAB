#include <stdio.h>

#define MAX 10
#define INF 999

void readMatrix(int cost[MAX][MAX], int n) {
    printf("Enter the adjacency matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }
}

void displayDistances(int distance[], int n, int source) {
    printf("\nShortest distances from source %d:\n", source);

    for(int i = 0; i < n; i++)
        printf("%d -> %d : %d\n", source, i, distance[i]);
}

void dijkstra(int cost[MAX][MAX], int n, int source) {
    int distance[MAX];
    int visited[MAX] = {0};
    int min, next;

    for(int i = 0; i < n; i++)
        distance[i] = cost[source][i];

    distance[source] = 0;
    visited[source] = 1;

    for(int i = 1; i < n; i++) {
        min = INF;

        for(int j = 0; j < n; j++) {
            if(!visited[j] && distance[j] < min) {
                min = distance[j];
                next = j;
            }
        }

        visited[next] = 1;

        for(int j = 0; j < n; j++) {
            if(!visited[j] &&
               min + cost[next][j] < distance[j]) {
                distance[j] = min + cost[next][j];
            }
        }
    }

    displayDistances(distance, n, source);
}

int main() {
    int n, source;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    readMatrix(cost, n);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(cost, n, source);

    return 0;
}