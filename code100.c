#include <stdio.h>

typedef struct {
    int val, idx;
} Node;

void merge(Node arr[], int left, int mid, int right, int count[]) {
    Node temp[100];
    int i = left, j = mid + 1, k = 0, rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(Node arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node arr[100];
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}