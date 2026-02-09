#include <stdio.h>
#include <stdlib.h>

// Linked list node
typedef struct Node {
    int Vertex;
    struct Node* Next;
} Node;

// Graph structure using adjacency list
typedef struct {
    int VertexCount;
    int Directed;   // 0 = undirected, 1 = directed
    Node** Array;
} Graph;

// Create a new adjacency node
Node* CreateNode(int v) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Vertex = v;
    NewNode->Next = NULL;
    return NewNode;
}

// Create a graph
Graph* CreateGraph(int vertices, int directed) {
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->VertexCount = vertices;
    G->Directed = directed;
    G->Array = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; ++i)
        G->Array[i] = NULL;

    return G;
}

// Add an edge
void AddEdge(Graph* G, int src, int dest) {
    Node* NewNode = CreateNode(dest);
    NewNode->Next = G->Array[src];
    G->Array[src] = NewNode;

    if (!G->Directed) {
        NewNode = CreateNode(src);
        NewNode->Next = G->Array[dest];
        G->Array[dest] = NewNode;
    }
}

// Display adjacency list
void DisplayGraph(Graph* G) {
    printf("Adjacency List:\n");
    for (int i = 0; i < G->VertexCount; ++i) {
        printf("%d -> ", i);
        Node* Temp = G->Array[i];
        while (Temp) {
            printf("%d ", Temp->Vertex);
            Temp = Temp->Next;
        }
        printf("\n");
    }
}

// Recursive DFS function
void DFSUtil(Graph* G, int Vertex, int* Visited) {
    Visited[Vertex] = 1; // mark as visited
    printf("%d ", Vertex);

    Node* Temp = G->Array[Vertex];
    while (Temp) {
        int AdjVertex = Temp->Vertex;
        if (!Visited[AdjVertex])
            DFSUtil(G, AdjVertex, Visited);
        Temp = Temp->Next;
    }
}

// DFS traversal for entire graph
void DFS(Graph* G, int StartVertex) {
    int* Visited = (int*)calloc(G->VertexCount, sizeof(int));
    printf("DFS starting from vertex %d:\n", StartVertex);
    DFSUtil(G, StartVertex, Visited);

    // If graph is disconnected — run DFS for unvisited nodes
    for (int i = 0; i < G->VertexCount; ++i)
        if (!Visited[i])
            DFSUtil(G, i, Visited);

    free(Visited);
}

// Free memory
void FreeGraph(Graph* G) {
    for (int i = 0; i < G->VertexCount; ++i) {
        Node* Temp = G->Array[i];
        while (Temp) {
            Node* Next = Temp->Next;
            free(Temp);
            Temp = Next;
        }
    }
    free(G->Array);
    free(G);
}

// Example usage
int main() {
    Graph* G = CreateGraph(5, 0); // Undirected graph with 5 vertices

    AddEdge(G, 0, 1);
    AddEdge(G, 0, 4);
    AddEdge(G, 1, 2);
    AddEdge(G, 1, 3);
    AddEdge(G, 1, 4);
    AddEdge(G, 2, 3);

    DisplayGraph(G);
    printf("\n");
    DFS(G, 0); // Start DFS from vertex 0

    FreeGraph(G);
    return 0;
}
