#include <stdio.h>

struct node
{
    int data;
    struct Node* next;
};

struct node *head = NULL;

void DeleteFromStart(){
    struct node *temp;
    if(head == NULL){
        printf("List is empty");
    }else{
        temp =head;
        head = head->next;
        free(temp);
        printf("Node deleted from the begginning");
    }
}

void DeleteAtLast(){
    struct node *temp , *temp1;
    if(head == NULL){
        printf("List is empty");
    }else if(head->next == NULL){
        temp = head;
        head = NULL;
        free(temp);
        printf("The only present node has been deleted");
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
        printf("Deleted the node from the end");
        
    }
}


void DeleteFromMiddle(){
    int loc;
    struct node *temp , *temp1;
    if(head == NULL){
        printf("List is empty");
        return;
    }
    printf("Enter the location to delete");
    scanf("%d" , &loc);
    if(loc == 1){
        temp = head;
        head = NULL;
        free(temp);
        printf("The only present node has been deleted");
        return;
    }
    temp = head;
    for(int i = 0 ; i < loc ; i ++){
        temp1 = temp;
        temp = temp->next;
        if(temp == NULL){
            printf("cant delete. Position not available");
            return;
        }
        temp1->next = temp->next;
        free(temp);
        printf("deleted");
    }
}

int main()
{
    
    return 0;
}