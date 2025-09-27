#include <stdio.h>
#include <stdlib.h>

void PrintRow(int** arr, int rowIndex, int cols) {
    for (int j = 0; j < cols; j++) {
        printf("%d ", arr[rowIndex][j]);
    }
    printf("\n");
}

void PrintColumn(int** arr, int colIndex, int rows) {
    for (int i = 0; i < rows; i++) {
        printf("%d ", arr[i][colIndex]);
    }
    printf("\n");
}

void ReplaceRowWithValue(int** arr, int rowIndex, int cols, int value) {
    for (int j = 0; j < cols; j++) {
        arr[rowIndex][j] = value;
    }
}

int main() {
    int rows, cols;
    int** arr;

    printf("Enter the number of rows and cols in the matrix: ");
    scanf("%d %d", &rows, &cols);

    arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int rowToPrint = 1;
    int colToPrint = 0;
    int rowToReplace = 2;
    int valueToSet = 99;

    PrintRow(arr, rowToPrint, cols);
    PrintColumn(arr, colToPrint, rows);
    ReplaceRowWithValue(arr, rowToReplace, cols, valueToSet);
    PrintRow(arr, rowToReplace, cols);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
