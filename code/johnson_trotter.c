#include <stdio.h>

#define LEFT -1
#define RIGHT 1

int getMobile(int a[], int dir[], int n) {
    int mobile = 0, mobileIndex = -1;

    for(int i = 0; i < n; i++) {
        if(dir[i] == LEFT && i > 0 &&
           a[i] > a[i - 1] && a[i] > mobile) {
            mobile = a[i];
            mobileIndex = i;
        }

        if(dir[i] == RIGHT && i < n - 1 &&
           a[i] > a[i + 1] && a[i] > mobile) {
            mobile = a[i];
            mobileIndex = i;
        }
    }

    return mobileIndex;
}

void printPermutation(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void initialize(int a[], int dir[], int n) {
    for(int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }
}

void generatePermutations(int a[], int dir[], int n) {
    int mobileIndex, swapIndex, temp;

    printf("\nGenerated permutations:\n");
    printPermutation(a, n);

    while(1) {
        mobileIndex = getMobile(a, dir, n);

        if(mobileIndex == -1)
            break;

        if(dir[mobileIndex] == LEFT)
            swapIndex = mobileIndex - 1;
        else
            swapIndex = mobileIndex + 1;

        temp = a[mobileIndex];
        a[mobileIndex] = a[swapIndex];
        a[swapIndex] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        mobileIndex = swapIndex;

        for(int i = 0; i < n; i++) {
            if(a[i] > a[mobileIndex])
                dir[i] = -dir[i];
        }

        printPermutation(a, n);
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int a[n], dir[n];

    initialize(a, dir, n);
    generatePermutations(a, dir, n);

    return 0;
}