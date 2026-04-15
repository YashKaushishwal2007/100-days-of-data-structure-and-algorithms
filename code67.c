#include<stdio.h>

int n;
int adj[100][100];
int visited[100];
int stack[100], top = -1;

void push(int x){
    stack[++top] = x;
}

void dfs(int v){
    visited[v] = 1;

    for(int i = 0; i < n; i++){
        if(adj[v][i] && !visited[i]){
            dfs(i);
        }
    }

    push(v);
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
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    while(top != -1){
        printf("%d ", stack[top--]);
    }

    return 0;
}