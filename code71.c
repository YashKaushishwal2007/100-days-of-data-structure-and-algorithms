#include<stdio.h>
#include<string.h>

int main(){
    int m, q;
    scanf("%d",&m);
    scanf("%d",&q);

    int table[m];

    for(int i = 0; i < m; i++){
        table[i] = -1;
    }

    while(q--){
        char op[10];
        int key;
        scanf("%s %d",op,&key);

        if(strcmp(op,"INSERT") == 0){
            int h = key % m;

            for(int i = 0; i < m; i++){
                int idx = (h + i*i) % m;
                if(table[idx] == -1){
                    table[idx] = key;
                    break;
                }
            }
        }
        else if(strcmp(op,"SEARCH") == 0){
            int h = key % m;
            int found = 0;

            for(int i = 0; i < m; i++){
                int idx = (h + i*i) % m;
                if(table[idx] == -1){
                    break;
                }
                if(table[idx] == key){
                    found = 1;
                    break;
                }
            }

            if(found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    return 0;
}