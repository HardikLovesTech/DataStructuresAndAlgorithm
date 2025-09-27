#include <stdio.h>

void InsertionSort(int arr[] , int n){
    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int Arr[] = {12, 11, 13, 5, 6};
    int N = 5;

    printf("Original Array:\n");
    for(int I = 0; I < N; I++){
        printf("%d ", Arr[I]);
    }
    printf("\n");

    InsertionSort(Arr, N);

    printf("Sorted Array:\n");
    for(int I = 0; I < N; I++){
        printf("%d ", Arr[I]);
    }
    printf("\n");

    return 0;
}
