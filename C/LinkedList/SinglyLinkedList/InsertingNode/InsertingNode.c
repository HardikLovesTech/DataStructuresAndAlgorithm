#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

struct Node *Head = NULL;

void BeginInsert()
{
    struct Node *NewNode;
    int Item;
    NewNode = (struct Node *)malloc(sizeof(struct Node));
    if (NewNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
    }
    else
    {
        printf("Enter the value of the node: ");
        scanf("%d", &Item);
        NewNode->Data = Item;
        NewNode->Next = Head;
        Head = NewNode;
        printf("New Node Inserted at Beginning\n");
    }
}

void InsertEnd()
{
    struct Node *NewNode, *Temp;
    int Item;
    NewNode = (struct Node *)malloc(sizeof(struct Node));
    if (NewNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
    }
    else
    {
        printf("Enter the value of the node: ");
        scanf("%d", &Item);
        NewNode->Data = Item;
        NewNode->Next = NULL;

        if (Head == NULL)
        {
            Head = NewNode;
        }
        else
        {
            Temp = Head;
            while (Temp->Next != NULL)
            {
                Temp = Temp->Next;
            }
            Temp->Next = NewNode;
        }
        printf("New Node Inserted at End\n");
    }
}

void MiddleInsert()
{
    int Loc, Item;
    struct Node *Temp, *NewNode;
    NewNode = (struct Node *)malloc(sizeof(struct Node));
    if (NewNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
    }
    else
    {
        printf("Enter the value of the node: ");
        scanf("%d", &Item);
        NewNode->Data = Item;

        printf("Enter the location (0-based index) after which to insert: ");
        scanf("%d", &Loc);

        Temp = Head;
        for (int i = 0; i < Loc; i++)
        {
            if (Temp == NULL)
            {
                printf("Index out of bounds!\n");
                free(NewNode);
                return;
            }
            Temp = Temp->Next;
        }

        if (Temp == NULL)
        {
            printf("Index out of bounds!\n");
            free(NewNode);
            return;
        }

        NewNode->Next = Temp->Next;
        Temp->Next = NewNode;
        printf("New Node Inserted at location %d\n", Loc);
    }
}

void DisplayList()
{
    struct Node *Temp = Head;
    printf("List: ");
    while (Temp != NULL)
    {
        printf("%d -> ", Temp->Data);
        Temp = Temp->Next;
    }
    printf("NULL\n");
}

int main()
{
    int Choice;
    while (1)
    {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Middle\n4. Display List\n5. Exit\nEnter your choice: ");
        scanf("%d", &Choice);
        switch (Choice)
        {
        case 1:
            BeginInsert();
            break;
        case 2:
            InsertEnd();
            break;
        case 3:
            MiddleInsert();
            break;
        case 4:
            DisplayList();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    }
    return 0;
}
