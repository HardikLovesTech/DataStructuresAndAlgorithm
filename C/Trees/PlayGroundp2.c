#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Key;
    struct Node* Left;
    struct Node* Right;
} Node;

Node* CreateNode(int Key) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Key = Key;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    return NewNode;
}

Node* InsertNode(Node *root , int key){
    if(root == NULL){
        return CreateNode(key);
    }
    if(key < root->Key){
        root->Left = InsertNode(root->Left, key);
    }
    else if(key > root->Key){
        root->Right = InsertNode(root->Right, key);
    }
    return root;
}

Node* SearchNode(Node *root , int key){
    if(root == NULL){
        return root;
    }
    if(key < root->Key){
        return SearchNode(root->Left, key);
    }
    else if(key > root->Key){
        return SearchNode(root->Right, key);
    }
}

Node *FindMin(Node *root){
    while (root && root->Left != NULL)
    {
        root = root->Left;
    }
    return root;
}

Node *DeleteNode(Node *root , int key){
    if(key < root->Key){
        root->Left = DeleteNode(root->Left , key);
    }
    else if(key > root->Key){
        root->Right = DeleteNode(root->Right , key);
    }
    else{
        if(root->Left == NULL){
            Node* temp = root->Right;
            free(root);
            return temp;
        }
        else{
            Node *temp = root->Left;
            free(root);
            return temp;
        }

        Node *temp = FindMin(root->Right);
        root->Key = temp->Key;
        root->Right = DeleteNode(root->Right , temp->Key);
    }
    return root;
}


