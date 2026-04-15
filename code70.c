#include<stdio.h>
#include<limits.h>

struct Edge{
    int u, v, w;
};

int main(){
    int n, m;
    scanf("%d %d",&n,&m);

    struct Edge edges[m];

    for(int i = 0; i < m; i++){
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
    }

    int src;
    scanf("%d",&src);

    int dist[n];

    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    int hasCycle = 0;

    for(int j = 0; j < m; j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            hasCycle = 1;
            break;
        }
    }

    if(hasCycle){
        printf("NEGATIVE CYCLE");
    } else {
        for(int i = 0; i < n; i++){
            printf("%d ", dist[i]);
        }
    }

    return 0;
}