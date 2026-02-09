#include <stdio.h>
#include <stdlib.h>

// Recursive Binary Search
int BinarySearch(int arr[], int start, int end, int target) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return BinarySearch(arr, start, mid - 1, target);
        return BinarySearch(arr, mid + 1, end, target);
    }
    return -1;
}

void test_binary_search() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = BinarySearch(arr, 0, n - 1, target);
    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found\n", target);
}

// Singly Linked List Implementation
typedef struct Node {
    int data;
    struct Node* next;
} Node;
#include <stdio.h>
#define MAX 10000
typedef struct { int r,c,v; } Triple;

int main(void) {
    int rows, cols, nz; scanf("%d%d%d", &rows, &cols, &nz);
    Triple a[MAX];
    for (int i=0;i<nz;++i) scanf("%d%d%d", &a[i].r, &a[i].c, &a[i].v);
    for (int c=0;c<cols;++c) for (int i=0;i<nz;++i) if (a[i].c == c) printf("%d %d %d\n", a[i].c, a[i].r, a[i].v);
    return 0;
}