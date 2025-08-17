#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent the 
// singly linked list
struct Node {
  
  // Data field - can be of 
  // any type and count
  int data;
  
  // Pointer to the next node
  struct Node* next;
};


struct Node* newNode(int data)
{
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node ));
  temp->data = data;
  temp->next = NULL;
  return temp;
};


void TraverseList(struct Node* head)
{
  while(head != NULL){
    printf("%d " , head->data);
    head = head->next;
  }
  printf("/n");
}

void main()
{
  struct Node* head = newNode(10);
  head->next = newNode(12);
  head->next->next = newNode(25);  

  TraverseList(head);
}


