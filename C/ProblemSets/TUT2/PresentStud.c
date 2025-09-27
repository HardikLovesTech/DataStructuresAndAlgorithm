#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, NumPresent, Roll;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    int* attendance = (int *)calloc(n, sizeof(int));
    if (attendance == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the number of students present: ");
    scanf("%d", &NumPresent);

    printf("Enter the roll numbers of present students (1 to %d):\n", n);
    for (i = 0; i < NumPresent; i++) {
        scanf("%d", &Roll);
        if (Roll >= 1 && Roll <= n) {
            attendance[Roll - 1] = 1;  
        } else {
            printf("Invalid roll number: %d\n", Roll);
        }
    }

    printf("\nPresent Students:\n");
    for (i = 0; i < n; i++) {
        if (attendance[i] == 1) {
            printf("Roll No. %d\n", i + 1);
        }
    }

    printf("\nAbsent Students:\n");
    for (i = 0; i < n; i++) {
        if (attendance[i] == 0) {
            printf("Roll No. %d\n", i + 1);
        }
    }

    free(attendance);

    printf("HEllO WORLD!!");
    return 0;
}
