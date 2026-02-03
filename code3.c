#include <stdio.h>


void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}


int linear_search(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            return i;   
        }
    }
    return -1;  
}

int main(){
    int element = 20;
    int arr[] = {1,2,3,4,5,20,25,30};
    int size = 8;

    display(arr, size);

    int result = linear_search(arr, size, element);

    if(result != -1){
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
