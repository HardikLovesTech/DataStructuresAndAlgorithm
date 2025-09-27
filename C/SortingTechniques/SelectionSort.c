#include <stdio.h>

void SelectionSort(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        int MinIdx = i;
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[MinIdx]){
                MinIdx = j;
            }
        }
            if(MinIdx != i){
                int temp = arr[i];
                arr[i] = arr[MinIdx];
                arr[MinIdx] = temp;
        }
    }
}

void PrintArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    PrintArray(arr, n);

    SelectionSort(arr, n);

    printf("Sorted array in descending order:\n");
    PrintArray(arr, n);

    return 0;
}
