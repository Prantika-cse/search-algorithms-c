/*
An online shop keep its product catalogs sorted by product id(whole number) in accending order.
when a customer search for a specific product id the system return true if the product id present in the catalog
else it returns false,which searching techinque is used to find the product id quickly from the catalog.
Implement this searching method uding a function. The function takes parameter product id list,size of the list and 
product id to be searched.
     

sample input:[2,8,9,16,18,26,38,48,51,90]
case1:product id to be reached:49
case 2:product id to be searche:26

*/
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
