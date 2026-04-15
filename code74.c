#include<stdio.h>
#include<string.h>

int main(){
    int n;
    scanf("%d",&n);

    char names[n][50];

    for(int i = 0; i < n; i++){
        scanf("%s", names[i]);
    }

    int maxCount = 0;
    char winner[50];

    for(int i = 0; i < n; i++){
        int count = 0;

        for(int j = 0; j < n; j++){
            if(strcmp(names[i], names[j]) == 0){
                count++;
            }
        }

        if(count > maxCount){
            maxCount = count;
            strcpy(winner, names[i]);
        }
        else if(count == maxCount){
            if(strcmp(names[i], winner) < 0){
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxCount);

    return 0;
}