#include <stdio.h>

int BinarySearch(int arr[] , int start , int end , int target){
    if(end >= start){
        int mid = start + (end - start)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] > target){
            return BinarySearch(arr , start , mid-1 , target);
        }
        return BinarySearch(arr , mid+1 , end , target);
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};  // Example sorted array
    int target = 7;  // The element we want to find
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements in the array

    int result = BinarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}