// #include <stdio.h>
// #define SIZE 5

// struct Queue {
//     int items[SIZE];
//     int front;
//     int rear;
// };

// void Initialize(struct Queue *q) {
//     q->front = -1;
//     q->rear = -1;
// }

// void Enqueue(struct Queue *q, int value) {
//     if (q->rear == SIZE - 1) {
//         printf("Queue Overflow! Cannot insert %d\n", value);
//     } else {
//         if (q->front == -1)
//             q->front = 0;
//         q->rear++;
//         q->items[q->rear] = value;
//         printf("%d inserted into queue.\n", value);
//     }
// }

// void Dequeue(struct Queue *q) {
//     if (q->front == -1 || q->front > q->rear) {
//         printf("Queue Underflow! Nothing to remove.\n");
//     } else {
//         printf("%d removed from queue.\n", q->items[q->front]);
//         q->front++;
//     }
// }

// void Display(struct Queue *q) {
//     if (q->front == -1 || q->front > q->rear) {
//         printf("Queue is empty.\n");
//     } else {
//         printf("Queue elements: ");
//         for (int i = q->front; i <= q->rear; i++) {
//             printf("%d ", q->items[i]);
//         }
//         printf("\n");
//     }
// }

// int main() {

// }


#include <stdio.h>
#include <stdlib.h>

#define NUM_QUEUES 3

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

// Initialize all queues in the array by setting their front and rear pointers to NULL
void InitializeQueues(struct Queue q[]) {
    for (int i = 0; i < NUM_QUEUES; i++) {
        // For an empty queue both front and rear should be NULL
        q[i].front = q[i].rear = NULL;
    }
}

// Insert a new value at the rear of the queue
void Enqueue(struct Queue *q, int value) {
    // Allocate a new node to hold the value
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // It is good practice to check malloc in real code; omitted here for brevity.
    newNode->data = value;    // store the value in the new node
    newNode->next = NULL;     // new node will be the last node, so next is NULL

    // If the queue is empty (rear == NULL), new node becomes both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        // Otherwise, link the current rear to the new node and update rear
        q->rear->next = newNode;
        q->rear = newNode;
    }
    // Informational message that insertion succeeded
    printf("%d inserted into queue.\n", value);
}

// Remove a value from the front of the queue
void Dequeue(struct Queue *q) {
    // If the queue is empty (front == NULL), nothing to remove
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    // Keep a temporary pointer to the current front so we can free it later
    struct Node *temp = q->front;
    // Print the value being removed
    printf("%d removed from queue.\n", temp->data);
    // Advance the front pointer to the next node
    q->front = q->front->next;

    // If advancing made the queue empty, make sure rear also becomes NULL
    if (q->front == NULL)
        q->rear = NULL;

    // Free the memory of the removed node to avoid memory leaks
    free(temp);
}

void Display(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue queues[NUM_QUEUES];
    InitializeQueues(queues);

    // Queue 0
    Enqueue(&queues[0], 10);
    Enqueue(&queues[0], 20);

    // Queue 1
    Enqueue(&queues[1], 100);
    Enqueue(&queues[1], 200);
    Dequeue(&queues[1]);

    // Queue 2
    Enqueue(&queues[2], 5);

    printf("\nDisplaying all queues:\n");
    for (int i = 0; i < NUM_QUEUES; i++) {
        printf("Queue %d: ", i);
        Display(&queues[i]);
    }

    return 0;
}
