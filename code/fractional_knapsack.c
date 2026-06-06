#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

void readItems(struct Item item[], int n) {
    printf("Enter weight and profit for each item:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d%d", &item[i].weight, &item[i].profit);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }
}

void sortItems(struct Item item[], int n) {
    struct Item temp;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(item[j].ratio < item[j + 1].ratio) {
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
    }
}

void fractionalKnapsack(struct Item item[], int n, int capacity) {
    float totalProfit = 0.0;

    sortItems(item, n);

    for(int i = 0; i < n; i++) {
        if(capacity >= item[i].weight) {
            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum obtainable profit = %.2f\n", totalProfit);
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    readItems(item, n);

    printf("Enter bag capacity: ");
    scanf("%d", &capacity);

    fractionalKnapsack(item, n, capacity);

    return 0;
}