#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* addNode(int data)    
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void TraverseList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* AddNodeAtFront(struct Node* head , int data)
{
    struct Node* new_node = addNode(data);
    new_node->next = head;
    return new_node;
}

struct Node* AddNodeAtEnd(struct Node* head, int data)
{
    struct Node* NewNode = addNode(data);

    if (head == NULL)  // If list is empty, new node becomes head
        return NewNode;

    struct Node* Last = head;
    while (Last->next != NULL) // Stop at last node
    {
        Last = Last->next;
    }
    Last->next = NewNode;

    return head;
}

bool SearchKey(struct Node* head ,int data)
{
    struct Node* curr = head;

    while (curr != NULL)
    {
        if (curr ->data == data)
        {
            return true;
        }
        curr = curr -> next;
    }
    return false;
}


int main()
{
    struct Node* head = addNode(15);
    head->next = addNode(32);
    head->next->next = addNode(12);

    TraverseList(head);

    head = AddNodeAtFront(head , 5); // Update head
    TraverseList(head);

    head = AddNodeAtEnd(head , 23);
    TraverseList(head);


    return 0;
}
