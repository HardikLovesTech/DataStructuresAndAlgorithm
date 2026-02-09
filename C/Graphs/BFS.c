#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define FALSE 0
#define TRUE 1

// ---------------------- Node structure for adjacency list ----------------------
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// ---------------------- Queue node structure ----------------------
typedef struct queue {
    int vertex;
    struct queue* link;
} QueueNode;

typedef struct queue* queue;
// ---------------------- Global variables ----------------------
Node* graph[MAX_VERTICES];
short int visited[MAX_VERTICES];
int n; // Number of vertices

// ---------------------- Queue functions ----------------------
void enqueue(queue* front, queue* rear, int vertex) {
    queue temp = (queue)malloc(sizeof(QueueNode));
    temp->vertex = vertex;
    temp->link = NULL;

    if (*rear) {
        (*rear)->link = temp;
    } else {
        *front = temp;
    }
    *rear = temp;
}

int dequeue(queue* front) {
    queue temp = *front;
    int item;

    if (!temp)
        return -1; // queue empty

    item = temp->vertex;
    *front = temp->link;
    free(temp);
    return item;
}

// ---------------------- Graph helper functions ----------------------
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    // Add edge from dest to src (since graph is undirected)
    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}
// ---------------------- BFS implementation ----------------------
void bfs(int v) {
    Node* w;
    queue front = NULL, rear = NULL;

    printf("%d ", v);
    visited[v] = TRUE;
    enqueue(&front, &rear, v);

    while (front) {
        v = dequeue(&front);
        for (w = graph[v]; w; w = w->next) {
            if (!visited[w->vertex]) {
                printf("%d ", w->vertex);
                visited[w->vertex] = TRUE;
                enqueue(&front, &rear, w->vertex);
            }
        }
    }
}

// ---------------------- Main function ----------------------
int main() {
    int i, edges, src, dest, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph
    for (i = 0; i < n; i++) {
        graph[i] = NULL;
        visited[i] = FALSE;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("BFS traversal starting from vertex %d:\n", startVertex);
    bfs(startVertex);

    return 0;
}
