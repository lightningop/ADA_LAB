#include <stdio.h>
#include <time.h>

#define MAX 100000

void merge(int a[], int low, int mid, int high) {
    int temp[MAX];
    int i = low, j = mid + 1, k = 0;

    while(i <= mid && j <= high) {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
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
    mergeSort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    displayArray(a, n);
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}