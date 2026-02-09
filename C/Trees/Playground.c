#include <stdbool.h>
#include <stdio.h>

//Node Structure
typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *Nodeptr;

//Here bascially nodeptr is the pointer to the location of the struct node

Nodeptr getNode(){

    //Creating temp nodeptr
    Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node));
    if(!temp){
        printf("Memory ALllocation failed!!");
    }
    temp->lchild = temp->rchild = NULL;
    return temp;

}


Nodeptr CreateBinaryTree(int item){
    int x;
    if(x != -1){
        Nodeptr temp = getNode();
        temp->data = item;
        printf("Enter the left child of %d (-1 for no child)" , item);
        scanf("%d" , &x);
        temp->lchild =  CreateBinaryTree(x);
        printf("Enter the right child of %d (-1 for no child)" , item);
        scanf("%d" , &x);
        temp->rchild= CreateBinaryTree(x);
        return temp;
    }
    return NULL;
}


//Traversals - Recursive

//Preorder
//Root --> Left --> Right
void PreOrderTraversal(Nodeptr node){
    if(node == NULL){
        return;
    }
    printf("%d" , node->data);
    PreOrderTraversal(node->lchild);
    PreOrderTraversal(node->rchild);
}



//Inorder
//Left --> Root --> Right
void InOrderTraversal(Nodeptr node){
    if(node == NULL){
        return;
    }
    InOrderTraversal(node->lchild);
    printf("%d" , node->data);
    InOrderTraversal(node->rchild);
}

//Post Order
//Left --> Right --> Root
void PostOrderTraversal(Nodeptr node){
    if(node == NULL){
        return;
    }
    PostOrderTraversal(node->lchild);
    PostOrderTraversal(node->rchild);
    printf("%d" , node->data);
}


//Traversals - Iterative
//Preorder

//For this we need to create a stack

struct stack{
    struct node* data[100];
    int top;
};

typedef struct stack stack;

void push(stack *s , struct node* data){
    s->data[++s->top] = data;
}

struct node* pop(stack *s){
    return (s->data[s->top--]);
}

bool isEmpty(stack *s){
    return (s->top == -1);
}

void PreorderTraversalIterative(struct Node *root){
    stack s;
    s.top = -1;
    s.data[++s.top] = root;
    //Jab tk stack empty nahi hai matlab top == -1
    while(!isEmpty(&s)){
        struct Node * curr =  pop(&s);
        printf("%d" , curr->data);
        if(curr->rchild){
            push(&s, curr->rchild);
        }
        if(curr->lchild){
            push(&s, curr->lchild);
        }
    } 
}

//InorderTraversal
void InorderTraversalIterative(struct Node *root){
    stack s;
    s.top = -1;
    struct Node * curr =  root;
    while(curr ==  NULL || !isEmpty(&s)){
        while (curr->data != NULL)
        {
            push(&s , curr);
            curr = curr->lchild;
        }


        curr = pop(&s);
        printf("%d" , curr->data);

        
        curr = curr->rchild;

    }
}

//Postorder
void PostorderTraversalIterative(struct Node *root){
    stack s1 , s2;
    s1.top = s2.top = -1; 
    push(&s1 , root); // push root onto s1

    while (!isEmpty(&s1))
    {
        struct Node * curr = pop(&s1); // pop from s1
        push(&s2 , curr); // push the popped onto s2
        //left ya right bacha hoga toh andar daal de
        if(curr->lchild) push(&s1 , curr->lchild);
        if(curr->rchild) push(&s1 , curr->rchild);

        while (!isEmpty(&s2))
        {
            struct Node *curr = pop(&s2); // pop a node from s2
            printf("%d" , curr->data); // print the node's data (nodes popped from s2 produce postorder)
        }
        
    }
}

//Level Order Traversal
struct Queue
{
    struct Node* arr[100];
    int front;
    int rear;
};

typedef struct Queue queue;

void Initialize(queue *q){
    q->front = -1;
    q->rear = -1;
}

void Enqueue(queue *q , struct Node *node){
    if(q->front == -1){
        q->front = 0;
    }
    q->arr[++q->rear] = node;
}

struct Node * Dequeue(queue *q){
    return q->arr[q->front++];
}

int IsEmptyT(queue *q){
    return (q->front == -1 || q->front > q->rear);
}

void LevelorderTraversalIterative(struct Node *root){
    queue q;
    Initialize(&q);
    while (!IsEmptyT(&q))
    {
        struct Node *curr = Dequeue(&q);
        printf("%d" , curr->data);
        if(curr->lchild != NULL) Enqueue(&q , curr->lchild);
        if(curr->rchild != NULL) Enqueue(&q , curr->rchild);
    }
    
}

bool Search(struct Node *root , int ele){
    if(root->data == ele){
        return true;
    }
    bool LeftSearch = Search( root->lchild , ele);
    bool RightSearch = Search( root->rchild , ele);

    return (LeftSearch || RightSearch);
}


struct Node *Copy(struct Node *root){
    struct Node  *temp = getNode(root->data);
    temp->lchild = Copy(root->lchild);
    temp->rchild = Copy(root->rchild);
}

int CountNodes(struct Node *root){
    if(root == NULL){
        return 0;
    }
    return ( 1 + CountNodes(root->lchild) + CountNodes(root->rchild));
}

int CountLeafNodes(struct Node *root){
    if(root == NULL){
        return 0;
    }

    if(root->lchild == NULL && root->rchild == NULL){
        return 1;
    }

    return (CountLeafNodes(root->lchild) + CountLeafNodes(root->rchild));
}
