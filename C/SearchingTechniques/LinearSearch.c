#include <stdio.h>

int LinearSearch(int arr[], int n, int target);

int main() {
    int arr[] = {1, 2, 3, 34, 4, 5};
    int n = 6;
    int target = 3;
    
    int index = LinearSearch(arr, n, target);
    
    if(index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}

int LinearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}
