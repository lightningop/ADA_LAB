#include <stdio.h>
#include <time.h>

#define MAX 100000

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if(left < n && a[left] > a[largest])
        largest = left;

    if(right < n && a[right] > a[largest])
        largest = right;

    if(largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void buildHeap(int a[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

void heapSort(int a[], int n) {
    int temp;

    buildHeap(a, n);

    for(int i = n - 1; i > 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
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
    heapSort(a, n);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    displayArray(a, n);
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}