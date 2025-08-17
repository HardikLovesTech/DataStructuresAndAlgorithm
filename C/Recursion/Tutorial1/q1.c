#include <stdio.h>

int main(){
    int size = 0;
    printf("Enter the number of elements of the array:");
    scanf("%d" , &size);
    int arr[size];
    int *ptr = arr;
    for(int i = 0 ; i < size ; i++){
        scanf("%d" , (ptr+i));
    }
    for(int i = 0 ; i < size ; i++){
        printf("%d " , *(ptr+i));
    }
}