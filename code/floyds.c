#include <stdio.h>

#define MAX 10
#define INF 999

void readMatrix(int cost[MAX][MAX], int n) {
    printf("Enter the cost matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
}

void displayMatrix(int cost[MAX][MAX], int n) {
    printf("\nShortest path matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cost[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int cost[MAX][MAX], int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(cost[i][k] + cost[k][j] < cost[i][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }

    displayMatrix(cost, n);
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    readMatrix(cost, n);
    floydWarshall(cost, n);

    return 0;
}