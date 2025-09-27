#include <stdio.h>
#include <string.h>

struct Student
{
    int RollNumber;
    char Name[50];
    int Marks[3];
    int TotalMarks;
    float AverageMarks;
};

void CalculateTotals(struct Student* s)
{
    s->TotalMarks = 0;
    for(int i = 0; i < 3; i++)
    {
        s->TotalMarks += s->Marks[i];
    }
    s->AverageMarks = s->TotalMarks / 3.0;
}

void RecursiveSort(struct Student students[], int n, int index)
{
    if(index >= n - 1)
        return;

    int minIndex = index;
    for(int j = index + 1; j < n; j++)
    {
        if(students[j].RollNumber < students[minIndex].RollNumber)
            minIndex = j;
    }

    if(minIndex != index)
    {
        struct Student temp = students[index];
        students[index] = students[minIndex];
        students[minIndex] = temp;
    }

    RecursiveSort(students, n, index + 1);
}

int RecursiveSearch(struct Student students[], int n, int roll, int index)
{
    if(index >= n)
        return -1;

    if(students[index].RollNumber == roll)
        return index;

    return RecursiveSearch(students, n, roll, index + 1);
}

void DisplayStudent(struct Student* s)
{
    printf("Roll Number: %d\n", s->RollNumber);
    printf("Name: %s\n", s->Name);
    printf("Marks: %d %d %d\n", s->Marks[0], s->Marks[1], s->Marks[2]);
    printf("Total Marks: %d\n", s->TotalMarks);
    printf("Average Marks: %.2f\n", s->AverageMarks);
    printf("-------------------------\n");
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    struct Student* ptr;

    for(int i = 0; i < n; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].RollNumber);
        printf("Name: ");
        scanf(" %[^\n]", students[i].Name); 
        printf("Enter marks for 3 subjects: ");
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &students[i].Marks[j]);
        }
        CalculateTotals(&students[i]); 
        printf("\n");
    }

    RecursiveSort(students, n, 0);

    printf("Sorted student records:\n");
    ptr = students; 
    for(int i = 0; i < n; i++)
    {
        DisplayStudent(ptr);
        ptr++; 
    }

    int rollToSearch;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollToSearch);

    int foundIndex = RecursiveSearch(students, n, rollToSearch, 0);
    if(foundIndex != -1)
    {
        printf("Student found:\n");
        DisplayStudent(&students[foundIndex]);
    }
    else
    {
        printf("Student with Roll Number %d not found.\n", rollToSearch);
    }

    return 0;
}
