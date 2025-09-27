#include <stdio.h>
int main() {
    int marks[5][3];
    int *ptr = &marks[0][0];

    printf("Enter marks for %d 5 in %d 3:\n", 5, 3);
    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%d", (ptr + i * 3 + j));
        }
    }

    printf("\nTotal marks for each student:\n");
    for (int i = 0; i < 5; i++) {
        int total = 0;
        for (int j = 0; j < 3; j++) {
            total += *(ptr + i * 3 + j);
        }
        printf("Student %d: %d\n", i + 1, total);
    }

    printf("\nAverage marks for each subject:\n");
    for (int j = 0; j < 3; j++) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += *(ptr + i * 3 + j);
        }
        float average = (float)sum / 5;
        printf("Subject %d: %.2f\n", j + 1, average);
    }

    return 0;
}
