#include <stdio.h>
#include <stdlib.h>

typedef struct node * N;

struct node
{
   int data;
   struct node *prev;
   struct node *next;
};

N head = NULL;

void DeleteBeginning(){
    N temp;
    if(head == NULL){
        printf("MT");
        return;
    }
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void DeleteEnd(){
    N temp;
    if(head == NULL){
        printf("MT");
        return;
    }
    temp = head;
    while (temp->next != NULL   )
    {
        temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next = NULL;
    }
    else{
        head = NULL;
    }
    free(temp);
    printf("Deleted Node");
    
}



void DeleteMiddle(){
    N temp;
    int loc , i;
    printf("Enter location to delete");
    scanf("%d" ,&loc);
    if(head == NULL){
        printf("MT");
        return;
    }
    temp = head;
    for(i = 0 ; i < loc ; i ++){
        if(temp->next == NULL){
            printf("Invalid!!");
            return;
        }
        temp = temp->next;
    }
    if(temp == NULL){
        printf("posn does not exist");
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    if(temp == head);
    head  = temp->next;
    free(temp);
    printf("Deleted");
}