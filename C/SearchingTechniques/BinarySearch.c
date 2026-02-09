#include <stdio.h>

int BinarySearch(int arr[], int key, int low, int high);
int binarySearch(int arr[], int low, int high, int key);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 34}; 
    int n = 6;
    int target = 3;
    
    int index = BinarySearch(arr, target, 0, n - 1);
    
    if(index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}

int BinarySearch(int arr[], int key, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// if(end >= start){
//         int mid = start + (end - start)/2;
//         if(arr[mid] == target){
//             return mid;
//         }
//         if(arr[mid] > target){
//             return BinarySearch(arr , start , mid-1 , target);
//         }
//         return BinarySearch(arr , mid+1 , end , target);
//     }
//     return -1;

int binarySearch(int arr[], int low, int high, int key){
    if(high >= low){
        int mid = low + (high - low)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key){
            return binarySearch(arr, low,  mid-1, key);
        }
        return binarySearch(arr, mid+1,  high, key);

    }
    return -1;
}