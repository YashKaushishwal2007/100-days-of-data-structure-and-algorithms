#include <stdio.h>
#include <stdlib.h>

int cmpStart(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && heap[l] < heap[smallest])
        smallest = l;
    if (r < n && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void insertHeap(int heap[], int *size, int val) {
    heap[*size] = val;
    int i = *size;
    (*size)++;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void extractMin(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    int start[100], end[100];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &end[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (start[i] > start[j]) {
                swap(&start[i], &start[j]);
                swap(&end[i], &end[j]);
            }
        }
    }

    int heap[100], size = 0;

    insertHeap(heap, &size, end[0]);

    for (int i = 1; i < n; i++) {
        if (start[i] >= heap[0]) {
            extractMin(heap, &size);
        }
        insertHeap(heap, &size, end[i]);
    }

    printf("%d", size);
    return 0;
}