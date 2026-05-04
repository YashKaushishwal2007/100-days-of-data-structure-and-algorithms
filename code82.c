#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int upperBound(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d", lb, ub);

    return 0;
}