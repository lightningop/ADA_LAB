#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void readItems(int weight[], int profit[], int n) {
    printf("Enter item weights:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter item profits:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d", &profit[i]);
}

int knapsack(int n, int weight[], int profit[], int capacity) {
    int dp[n + 1][capacity + 1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= capacity; j++) {

            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(weight[i] <= j)
                dp[i][j] = max(
                    profit[i] + dp[i - 1][j - weight[i]],
                    dp[i - 1][j]
                );

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1], profit[n + 1];

    readItems(weight, profit, n);

    printf("Enter bag capacity: ");
    scanf("%d", &capacity);

    int result = knapsack(n, weight, profit, capacity);

    printf("Maximum obtainable profit = %d\n", result);

    return 0;
}