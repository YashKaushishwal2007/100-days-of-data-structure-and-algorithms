
#include <stdio.h>


void mergeLogs(int a[], int p, int b[], int q, int result[]) {
    int i = 0, j = 0, k = 0;

    
    while (i < p && j < q) {
        if (a[i] < b[j]) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }

    
    while (i < p) {
        result[k++] = a[i++];
    }


    while (j < q) {
        result[k++] = b[j++];
    }
}


void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int p, q;


    scanf("%d", &p);
    int a[p];

    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    int b[q];

    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int result[p + q];

    
    mergeLogs(a, p, b, q, result);


    display(result, p + q);

    return 0;
}
