#include <stdio.h>
#include <stdlib.h>

int x[20];
int count = 0;

int place(int row, int col) {
    for(int i = 1; i < row; i++) {
        if(x[i] == col || abs(x[i] - col) == abs(i - row))
            return 0;
    }

    return 1;
}

void printBoard(int n) {
    printf("\nArrangement %d:\n", count);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(x[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void nQueens(int row, int n) {
    for(int col = 1; col <= n; col++) {
        if(place(row, col)) {
            x[row] = col;

            if(row == n) {
                count++;
                printBoard(n);
            }
            else {
                nQueens(row + 1, n);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter value of N: ");
    scanf("%d", &n);

    nQueens(1, n);

    if(count == 0)
        printf("No valid solution found.");

    return 0;
}