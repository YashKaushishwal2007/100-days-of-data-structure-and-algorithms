#include <stdio.h>


void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void reverse(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int temp;

    while(left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int n, i;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    display(arr, n);        

    reverse(arr, n);        

    printf("After reverse:\n");
    display(arr, n);        

    return 0;
}
