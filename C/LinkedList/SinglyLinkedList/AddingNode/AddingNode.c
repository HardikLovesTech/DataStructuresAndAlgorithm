#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct Node* next;
};
struct node* head = 0;

// struct Node* addNode(int data)    
// {
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->data = data;
//     temp->next = NULL;
//     return temp;
// }

// void TraverseList(struct Node* head)
// {
//     while (head != NULL)
//     {
//         printf("%d ", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

// struct Node* AddNodeAtFront(struct Node* head , int data)
// {
//     struct Node* new_node = addNode(data);
//     new_node->next = head;
//     return new_node;
// }

// struct Node* AddNodeAtEnd(struct Node* head, int data)
// {
//     struct Node* NewNode = addNode(data);

//     if (head == NULL)  // If list is empty, new node becomes head
//         return NewNode;

//     struct Node* Last = head;
//     while (Last->next != NULL) // Stop at last node
//     {
//         Last = Last->next;
//     }
//     Last->next = NewNode;

//     return head;
// }

// bool SearchKey(struct Node* head ,int data)
// {
//     struct Node* curr = head;

//     while (curr != NULL)
//     {
//         if (curr ->data == data)
//         {
//             return true;
//         }
//         curr = curr -> next;
//     }
//     return false;
// }


void InsertAtBeggining(){
    struct node *newNode;
    int item;
    newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("\nOverflow");
    }
    else{
        printf("Enter Value: ");
        scanf("%d" , &item);
        newNode->data = item;
        newNode->next = head;
        head = newNode;
        printf("\n New Node Inserted");
        
    }
}

void InsertAtEnd(){
    struct node  *newNode , *temp;
    int item;
    newNode = (struct node *)nalloc(sizeof(struct node));
    if(newNode == NULL){
        printf("\nOverflow");
    }
    else{
        newNode->data = item;
        newNode->next = NULL;
        if (head == NULL){
            head = newNode;
            printf("\n New Node Inserted"); 
        }
        else{
            temp = head;
            while (temp->next == NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            printf("\nNew Node Inserted");
            
        }

        
    }
}


void InsertInMiddle(){
    int i , loc , item;
    struct node *newNode , *temp ; 
    newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL){
        ("/nOverflow");
    }
    else{
        printf("Enter the element value");
        scanf("%d" , &item);
        newNode->data = item;
        printf("Enter the location you want to enter the item");
        scanf("%d" , &loc);
        temp = head;
        for(i = 0 ; i < loc ; i++){
            if(temp == NULL){
                printf("Unable to insert - location size exceeded");
                return ;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("New node inserted");
    }
}

void DeleteNodeAtFront(){
    struct node *temp;
    if (head == NULL)   
    {
        printf("\n List is empty");
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
        printf("\nNode deleted from the front");
    }
}

void DeleteNodeAtLast(){
    struct node *temp , *temp1;
    if(head == NULL){
        printf("\nList is empty");
    }
    else if(head->next == NULL){
        temp = head;
        head = NULL;
        free(temp);
        printf("\nOnly node of the list is deleted");
    }
    else{
        temp = head;
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        free(temp);
        printf("\nDeleted Node from the end");
    }
}

int main()
{
    // head->next = addNode(32);
    // head->next->next = addNode(12);

    // TraverseList(head);

    // head = AddNodeAtFront(head , 5); // Update head
    // TraverseList(head);

    // head = AddNodeAtEnd(head , 23);
    // TraverseList(head);


    return 0;
}
