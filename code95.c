#include <stdio.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float buckets[100][100];
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];
        buckets[idx][count[idx]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], count[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%.6f ", arr[i]);
    }

    return 0;
}