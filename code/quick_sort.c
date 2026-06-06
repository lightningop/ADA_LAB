#include <stdio.h>
#include <time.h>

#define MAX 100000

void quickSort(int a[], int low, int high) {
    int i, j, pivot, temp;

    if(low < high) {
        pivot = low;
        i = low;
        j = high;

        while(i < j) {
            while(a[i] <= a[pivot] && i < high)
                i++;

            while(a[j] > a[pivot])
                j--;

            if(i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

void readArray(int a[], int n) {
    printf("Enter array elements:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void displayArray(int a[], int n) {
    printf("\nSorted array:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main() {
    int n;
    int a[MAX];
    clock_t start, end;
    double time_taken;

    printf("Enter size of array: ");
    scanf("%d", &n);

    readArray(a, n);

    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    displayArray(a, n);
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}