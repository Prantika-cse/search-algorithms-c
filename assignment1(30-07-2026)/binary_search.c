#include <stdio.h>
#include<stdbool.h>

bool binarySearch(int arr[],int size,int target)
{
    int low=0;
    int high=size-1;
   
    while(low<=high)
    {
        int mid=(low+high)/2;
         if(arr[mid]==target){
           return true;  
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return false;
}


int main()
{
     int n;
    printf("Input the size of array:");
     scanf("%d",&n);
     int arr[n];
     printf("Input an array:");
     for(int i=0;i<n;i++){
     scanf("%d",&arr[i]);
     }
     int target;
     printf("Enter the target:");
     scanf("%d",&target);
     if(binarySearch(arr,n,target)){
        printf("true");
     }else{
        printf("false");
     }
    return 0;
}