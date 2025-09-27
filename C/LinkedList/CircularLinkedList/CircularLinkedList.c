#include <stdio.h>
#include <stdlib.h>
struct cnode
{
   int data;
    struct cnode *link;
};

typedef struct cnode * cn;

cn head = NULL;

cn insfrl(cn last){
    cn temp = (cn)malloc(sizeof(struct cnode));
    if(temp == NULL){
        printf("Memory Allocation failed");
        return;
    }
    printf("Enter the element:");
    scanf("%d" , &temp->data);
    if(last == NULL){
        last = temp;
    }
    else{
        last->link = last;
        temp->link = last->link;
        return last;
    }
}

//inserting in the end using last pointer

cn inslast(cn last){
    cn temp = (cn)malloc(sizeof(struct cnode));
    cn curr;
    if(temp == NULL){
        printf("Memory Allocation failed");
        return head;
    }
    printf("Enter the element:");
    scanf("%d" , &temp->data);
    if(last == NULL){
        last = temp;
        last->link = last;
    }
    else{
        temp->link = last->link;
        last->link = temp;
        temp = last;
        return last;
    }
}