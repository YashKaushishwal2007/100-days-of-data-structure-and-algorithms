#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
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

    int curr_start = start[0];
    int curr_end = end[0];

    for (int i = 1; i < n; i++) {
        if (start[i] <= curr_end) {
            if (end[i] > curr_end)
                curr_end = end[i];
        } else {
            printf("%d %d\n", curr_start, curr_end);
            curr_start = start[i];
            curr_end = end[i];
        }
    }

    printf("%d %d", curr_start, curr_end);

    return 0;
}