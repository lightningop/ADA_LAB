#include <stdio.h>

#define MAX 10
#define INF 999

void readMatrix(int cost[MAX][MAX], int n) {
    printf("Enter the adjacency matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }
}

void primMST(int cost[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int min, u = 0, v = 0;
    int mincost = 0;
    int edgeCount = 1;

    visited[0] = 1;

    printf("\nEdges selected for MST:\n");

    while(edgeCount < n) {
        min = INF;

        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                for(int j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", u, v, min);

        mincost += min;
        visited[v] = 1;
        edgeCount++;
    }

    printf("Total cost of MST = %d\n", mincost);
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    readMatrix(cost, n);
    primMST(cost, n);

    return 0;
}