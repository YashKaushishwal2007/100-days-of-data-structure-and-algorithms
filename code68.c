#include<stdio.h>

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
    int n;
    scanf("%d",&n);

    int adj[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&adj[i][j]);
        }
    }

    int indegree[n];

    for(int i = 0; i < n; i++){
        indegree[i] = 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adj[i][j]){
                indegree[j]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            enqueue(i);
        }
    }

    int count = 0;

    while(!isEmpty()){
        int v = dequeue();
        printf("%d ", v);
        count++;

        for(int i = 0; i < n; i++){
            if(adj[v][i]){
                indegree[i]--;
                if(indegree[i] == 0){
                    enqueue(i);
                }
            }
        }
    }

    if(count != n){
        printf("\nCycle exists");
    }

    return 0;
}