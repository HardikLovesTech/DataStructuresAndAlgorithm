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

void InsertBeginning(){
    N newNode;
    int item;
    newNode = (N)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Overload");
    }
    printf("Enter Value :");
    scanf("%d" , &item);
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}


void InsertEnd(){
    N newNode;
    N temp;
    int item;
    newNode = (N)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Overload");
        return;
    }
    printf("Enter value");
    scanf("%d" , &item);
    newNode->data = item;
    newNode->prev = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
    }else{
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        printf("Node Inserted At the end");
    }
}


void InsertMiddle(){
    N newNode;
    N temp;
    int item , loc;
    printf("Location");
    scanf("%d" , &loc);
    temp = head;
    for(int i = 0 ; i < loc ; i++){
        if(temp->next == NULL){
            printf("Invalid");
        }
        temp = temp->next;
    }
    newNode = (N)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Overload");
        return;
    }
    printf("Value");
    scanf("%d" , &item);
    newNode->data = item;
    newNode->next = temp->next;
    newNode->prev = temp->prev;
    if(temp->next != NULL){
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    printf("inserted");
}


