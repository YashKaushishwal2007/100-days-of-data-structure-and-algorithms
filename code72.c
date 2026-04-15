#include<stdio.h>
#include<string.h>

int main(){
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    for(int i = 0; s[i] != '\0'; i++){
        int idx = s[i] - 'a';
        freq[idx]++;

        if(freq[idx] == 2){
            printf("%c", s[i]);
            return 0;
        }
    }

    printf("-1");
    return 0;
}