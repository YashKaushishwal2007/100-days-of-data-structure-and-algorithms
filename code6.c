#include <stdio.h>


void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}


int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;

    int j = 0;   

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    return j + 1;   
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int newSize = removeDuplicates(arr, n);

    display(arr, newSize);

    return 0;
}
