#include <stdio.h>

#define MAX 10

void readGraph(int adj[MAX][MAX], int n) {
    int i, j;

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void findIndegree(int adj[MAX][MAX], int indegree[], int n) {
    int i, j;

    for(i = 0; i < n; i++)
        indegree[i] = 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j])
                indegree[j]++;
        }
    }
}

void topologicalSort(int adj[MAX][MAX], int n) {
    int indegree[MAX];
    int queue[MAX];
    int front = 0, rear = 0;
    int i, j, v, count = 0;

    findIndegree(adj, indegree, n);

    for(i = 0; i < n; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    printf("\nTopological sorting result:\n");

    while(front < rear) {
        v = queue[front++];
        printf("%d ", v);
        count++;

        for(j = 0; j < n; j++) {
            if(adj[v][j]) {
                indegree[j]--;

                if(indegree[j] == 0)
                    queue[rear++] = j;
            }
        }
    }

    if(count != n)
        printf("\nCycle detected in the graph.");

    printf("\n");
}

int main() {
    int adj[MAX][MAX];
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    readGraph(adj, n);
    topologicalSort(adj, n);

    return 0;
}