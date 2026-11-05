#include<stdio.h>
void insertion_sort(int arr[],int size){
    for(int i=1;i<size;i++){
        int current=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>=current){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=current;
    }
      for(int i=0;i<size;i++){
       printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){

     int n;
    printf("Input the size of array:");
     scanf("%d",&n);
     int arr[n];
     printf("Input an array:");
     for(int i=0;i<n;i++){
      scanf("%d",&arr[i]);
     }
     insertion_sort(arr,n);
    return 0;
    
}