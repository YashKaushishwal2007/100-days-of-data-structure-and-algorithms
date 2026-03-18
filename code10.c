#include <stdio.h>
#include <string.h>

int isPalindrome(char s[]) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return 0;  
        }
        left++;
        right--;
    }
    return 1;   
}

int main() {
    char s[100];

    
    scanf("%s", s);

    if (isPalindrome(s))
        printf("YES");
    else
        printf("NO");

    return 0;
}
