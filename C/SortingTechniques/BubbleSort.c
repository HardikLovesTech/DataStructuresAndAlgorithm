#include <stdio.h>

void BubbleSort(int arr[], int n);

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = 6;

    BubbleSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


void BubbleSort(int arr[] , int n){ 
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}