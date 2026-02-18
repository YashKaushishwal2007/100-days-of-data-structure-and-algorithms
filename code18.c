#include <stdio.h>

int main() {
    int n, k, i;


    scanf("%d", &n);

    int arr[n];

    
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &k);

    
    k = k % n;

    
    for(int r = 0; r < k; r++) {
        int last = arr[n - 1];

        
        for(i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = last;
    }

    
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
