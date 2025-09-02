#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* AddNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* DeleteNode(int data , struct Node)
{
    while (data != data)
    {
        /* code */
    }
    
}


int main()
{
    
    return 0;
}