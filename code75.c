#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_len = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                if (max_len < (j - i + 1)) {
                    max_len = j - i + 1;
                }
            }
        }
    }
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLen(arr, n));
    return 0;
}