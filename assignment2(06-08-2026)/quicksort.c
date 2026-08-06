/*write a program to take input in array 10 unordered number and apply
quicksort to order the array in ascending order .
Input: array size=10
Array items= [8,2,10,6,5,12,18,9,4,11]
*/


#include <stdio.h>
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[10] = {8, 2, 10, 6, 5, 12, 18, 9, 4, 11};
    int n = 10;

    quickSort(arr, 0, n - 1);

    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}