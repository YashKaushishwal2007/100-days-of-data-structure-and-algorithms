#include<stdio.h>

void display(int arr[],int n){

    for(int i = 0; i<n ;i++)  {
    printf("%d\n",arr[i]);
    }

}

int insert_element(int arr[],int size , int element,int capacity,int index){
    if(size>=capacity){
    return -1;
    }
    for(int i = size-1;i>=index;i--){
        arr[i+1]=arr[i];

    }
    arr[index]=element;
    return 1;
}

int main(){
    int arr[10] ={1,2,3,5,6};
    
     int size = 5; int element= 4;int index = 3;
     display(arr,size);
     insert_element(arr,size,element,10,index);
     size+=1;
     display(arr,size);

     return 0;

}
