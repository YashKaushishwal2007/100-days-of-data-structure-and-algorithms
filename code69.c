#include<stdio.h>
#include<limits.h>

int n;

int minDistance(int dist[], int visited[]){
    int min = INT_MAX, min_index = -1;

    for(int i = 0; i < n; i++){
        if(!visited[i] && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int main(){
    scanf("%d",&n);

    int adj[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&adj[i][j]);
        }
    }

    int src;
    scanf("%d",&src);

    int dist[n], visited[n];

    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for(int count = 0; count < n - 1; count++){
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for(int v = 0; v < n; v++){
            if(!visited[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]){
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", dist[i]);
    }

    return 0;
}