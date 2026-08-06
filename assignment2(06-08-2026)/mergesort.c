/*write a program to the input marks of 10 student randomly in an array 
sort the array using merge sort and show the highest and lowest marks'
Input:size of array=10
[80,73,92,86,47,92,58,91,48]
*/


#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int temp[10];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++; k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++; k++;
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[10] = {80, 73, 59, 92, 86, 47, 92, 58, 91, 48};
    int n = 10;

    mergeSort(arr, 0, n - 1);

    printf("Sorted marks:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nLowest marks = %d", arr[0]);
    printf("\nHighest marks = %d", arr[n - 1]);

    return 0;
}