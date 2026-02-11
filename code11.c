#include <stdio.h>

int main() {
    int m, n;

    
    scanf("%d %d", &m, &n);

    int a[m][n], b[m][n], sum[m][n];

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", sum[i][j]);

            if (j < n - 1)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
