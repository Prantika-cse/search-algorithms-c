/*
In a book library are stored using there acc no. Acc no. is the hole number that cosist 3 digit maximum. Consider an array where access number of books are stored in unorganised way.
The librarian wants to search for a specific access number in the array. Which searching methodology the librarian must follow . Write the programme to implement this subject 
technique.
*/
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
