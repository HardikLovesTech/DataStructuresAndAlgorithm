#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Left;
    struct Node *Right;
    int Height;
};

// Helper function to get height
int Height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->Height;
}

// Create a new node
struct Node* NewNode(int Data) {
    struct Node* Node = (struct Node*)malloc(sizeof(struct Node));
    Node->Data = Data;
    Node->Left = Node->Right = NULL;
    Node->Height = 1;
    return Node;
}

// Get balance factor
int GetBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return Height(N->Left) - Height(N->Right);
}

// Right rotation
struct Node* RightRotate(struct Node *y) {
    struct Node *x = y->Left;
    struct Node *T2 = x->Right;

    x->Right = y;
    y->Left = T2;

    y->Height = 1 + ((Height(y->Left) > Height(y->Right)) ? Height(y->Left) : Height(y->Right));
    x->Height = 1 + ((Height(x->Left) > Height(x->Right)) ? Height(x->Left) : Height(x->Right));

    return x;
}

// Left rotation
struct Node* LeftRotate(struct Node *x) {
        struct Node *y = x->Right;
    struct Node *T2 = y->Left;

    y->Left = x;
    x->Right = T2;

    y->Height = 1 + ((Height(y->Left) > Height(y->Right)) ? Height(y->Left) : Height(y->Right));
    x->Height = 1 + ((Height(x->Left) > Height(x->Right)) ? Height(x->Left) : Height(x->Right));

    return y;
}

// Find the node with minimum value (used in deletion)
struct Node* MinValueNode(struct Node* Node) {
    struct Node* curr = Node;
    while (curr->Left != NULL)
    {
        curr = curr->Left;
    }
    return curr;
    
}

// Delete a node
struct Node* DeleteNode(struct Node* Root, int Key) {
    if(Key < Root->Data){
        Root->Left = DeleteNode(Root->Left , Key);
    }
    else if(Key > Root->Data){
        Root->Right = DeleteNode(Root->Right , Key);
    }
    else{
        if((Root->Left == NULL) || (Root->Right == NULL)){
            struct Node *temp = Root->Left ? Root->Left : Root->Right;
            if(temp == NULL){
                temp = Root;
                Root = NULL;
            }
            else{
                *Root = *temp;
                free(Root);
            }
        }
        else{
            struct Node *Temp = MinValueNode(&Root->Right);
            Root->Data = Temp->Data;
            Root->Right = DeleteNode(Root->Right , Temp->Data);
        }
    }
    Root->Height = 1 + ((Height(Root->Left) > Height(Root->Right)) ? Height(Root->Left) : Height(Root->Right));

    int Balance = GetBalance(Root);

    if (Balance > 1 && GetBalance(Root->Left) >= 0)
        return RightRotate(Root);

    if (Balance > 1 && GetBalance(Root->Left) < 0) {
        Root->Left = LeftRotate(Root->Left);
        return RightRotate(Root);
    }

    if (Balance < -1 && GetBalance(Root->Right) <= 0)
        return LeftRotate(Root);

    if (Balance < -1 && GetBalance(Root->Right) > 0) {
        Root->Right = RightRotate(Root->Right);
        return LeftRotate(Root);
    }

    return Root;
}
