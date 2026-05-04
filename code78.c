#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int selected[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        selected[i] = 0;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int edges = 0, total = 0;
    selected[1] = 1;

    while (edges < n - 1) {
        int min = INT_MAX, x = 0, y = 0;

        for (int i = 1; i <= n; i++) {
            if (selected[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        selected[y] = 1;
        total += graph[x][y];
        edges++;
    }

    printf("%d", total);
    return 0;
}