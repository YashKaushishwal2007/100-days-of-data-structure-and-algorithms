#include<stdio.h>


void display(int arr[] , int n){        
    for(int i = 0 ; i <n; i++){

    printf("%d\n",arr[i]);

    }
}

int index_deletion(int arr[],int size,int capacity,int index){    
    if(index >=capacity){
        return -1;
    }
    for (int i = index ;i < size-1 ; i++){
        arr[i] = arr[i+1];
    }
    
    return 1;
}

int main(){


    int arr[100]={10,20,30,40,50};
    int size;int index;
printf("enter size of the array:");
scanf("%d",&size);

printf("enter index of the array:");
scanf("%d",&index);
    
    display(arr,size);
    index_deletion(arr,size,100,index);
    size-=1;
    display(arr,size);

    return 0;
}