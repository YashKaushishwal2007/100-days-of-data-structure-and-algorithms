#include<stdio.h>

int n;
int adj[100][100];
int visited[100];
int recStack[100];

int dfs(int v){
    visited[v] = 1;
    recStack[v] = 1;

    for(int i = 0; i < n; i++){
        if(adj[v][i]){
            if(!visited[i]){
                if(dfs(i)) return 1;
            }
            else if(recStack[i]){
                return 1;
            }
        }
    }

    recStack[v] = 0;
    return 0;
}

int main(){
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        visited[i] = 0;
        recStack[i] = 0;
    }

    int hasCycle = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs(i)){
                hasCycle = 1;
                break;
            }
        }
    }

    if(hasCycle) printf("YES");
    else printf("NO");

    return 0;
}