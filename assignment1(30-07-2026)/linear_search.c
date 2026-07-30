#include<stdio.h>

void linearsearch(int arr[],int n,int target){
   int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
         count++;
        }
    }
    if(count==1){
        printf("The book is avilable in this library");
    }
    else{
        printf("The book is not avilable in this library");
    }
}
int main(){
    int n;
    printf("Input the size of array:");
     scanf("%d",&n);
     int acc[n];
     printf("Input an array:");
     for(int i=0;i<n;i++){
      scanf("%d",&acc[i]);
     }
     int target;
     printf("Enter the target:");
     scanf("%d",&target);
     linearsearch(acc,n,target);
    return 0;
}