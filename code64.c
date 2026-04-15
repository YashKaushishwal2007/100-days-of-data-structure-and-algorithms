#include<stdio.h>
#include<stdlib.h>

int queue[100], front = -1, rear = -1;

void enqueue(int x){
    if(rear == 99) return;
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue(){
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty(){
    if(front == -1 || front > rear) return 1;
    return 0;
}

int main(){
    int n, i, j, s;

    scanf("%d",&n);

    int adj[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }

    scanf("%d",&s);

    int visited[n];

    for(i=0;i<n;i++){
        visited[i] = 0;
    }

    enqueue(s);
    visited[s] = 1;

    while(!isEmpty()){
        int v = dequeue();
        printf("%d ",v);

        for(i=0;i<n;i++){
            if(adj[v][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}