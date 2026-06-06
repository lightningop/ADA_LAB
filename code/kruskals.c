#include <stdio.h>

#define MAX 10
#define INF 999

int parent[MAX];

int find(int i) {
    while(parent[i])
        i = parent[i];

    return i;
}

int unionSets(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }

    return 0;
}

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

void kruskalMST(int cost[MAX][MAX], int n) {
    int a, b, u, v;
    int min, mincost = 0;
    int edgeCount = 1;

    printf("\nEdges selected for MST:\n");

    while(edgeCount < n) {
        min = INF;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(unionSets(u, v)) {
            printf("%d -> %d : %d\n", a, b, min);
            mincost += min;
            edgeCount++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Total cost of MST = %d\n", mincost);
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    readMatrix(cost, n);
    kruskalMST(cost, n);

    return 0;
}