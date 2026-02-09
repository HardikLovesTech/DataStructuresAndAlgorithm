// #include <stdio.h>
// #include <stdlib.h>

// typedef struct{
//     int VertexCount;
//     int directed;
//     int **mat;
// } Graph;

// Graph* CreateGraph(int n , int directed){
//     Graph* G = (Graph*)malloc(sizeof(Graph));
//     if(!G) return NULL;
//     G->VertexCount = n;
//     G->directed = n;

//     G->mat = (int **)malloc(n *sizeof(int));
//     if(!G->mat){
//         free(G);    
//         return NULL;
//     }   
//     for (int i = 0; i < n; ++i) {
//         G->mat[i] = (int*)malloc(n * sizeof(int));
//         if (!G->mat[i]) {
//             // free previously allocated rows on failure
//             for (int k = 0; k < i; ++k) free(G->mat[k]);
//             free(G->mat);
//             free(G);
//             return NULL;
//         }
//         for (int j = 0; j < n; ++j) G->mat[i][j] = 0;
//     }
//     return G;

// }

// void AddEdge(Graph* G, int u, int v, int weight) {
//     if (!G) return;
//     if (u < 0 || u >= G->VertexCount || v < 0 || v >= G->VertexCount) return;
//     G->mat[u][v] = weight == 0 ? 1 : weight; // default weight 1 if 0 passed
//     if (!G->directed) G->mat[v][u] = G->mat[u][v];
// }

// void RemoveEdge(Graph* G, int u, int v) {
//     if (!G) return;
//     if (u < 0 || u >= G->VertexCount || v < 0 || v >= G->VertexCount) return;
//     G->mat[u][v] = 0;
//     if (!G->directed) G->mat[v][u] = 0;
// }


// int main()
// {
    
//     return 0;
// }



// typedef struct Node {
//     int Vertex;
//     struct Node* Next;
// } Node;


// Node* CreateNodeL(int v) {
//     Node* NewNode = (Node*)malloc(sizeof(Node));
//     NewNode->Vertex = v;
//     NewNode->Next = NULL;
//     return NewNode;
// }


// Graph* CreateGraphL(int vertices, int directed) {
//     Graph* G = (Graph*)malloc(sizeof(Graph));
//     G->VertexCount = vertices;
//     G->directed = directed;
//     G->mat = (Node**)malloc(vertices * sizeof(Node*));

//     for (int i = 0; i < vertices; ++i)
//         G->mat[i] = NULL;  // initially empty lists

//     return G;
// }

// void AddEdge(Graph* G, int src, int dest) {
//     if (!G || src < 0 || dest < 0 || src >= G->VertexCount || dest >= G->VertexCount)
//         return;

//     // Add dest to src's list
//     Node* NewNode = CreateNode(dest);
//     NewNode->Next = G->mat[src];
//     G->mat[src] = NewNode;

//     // If undirected, add src to dest's list
//     if (!G->directed) {
//         NewNode = CreateNode(src);
//         NewNode->Next = G->mat[dest];
//         G->mat[dest] = NewNode;
//     }
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define FALSE 0
#define TRUE 1

// Node structure for adjacency list
typedef struct Node {
    int Vertex;
    struct Node* Next;
} Node;

// Graph representation (array of adjacency lists)
Node* Graph[MAX_VERTICES];
short int Visited[MAX_VERTICES];
int N;  // number of vertices

// Function to create a new node
Node* CreateNode(int Vertex) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Vertex = Vertex;
    NewNode->Next = NULL;
    return NewNode;
}

// Function to add an edge (undirected)
void AddEdge(int Src, int Dest) {
    // Add dest to src's list
    Node* NewNode = CreateNode(Dest);
    NewNode->Next = Graph[Src];
    Graph[Src] = NewNode;

    // Since it's undirected, add src to dest's list
    NewNode = CreateNode(Src);
    NewNode->Next = Graph[Dest];
    Graph[Dest] = NewNode;
}

// Depth First Search function
void DFS(int V) {
    Node* W;
    Visited[V] = TRUE;
    printf("%5d", V);

    for (W = Graph[V]; W != NULL; W = W->Next) {
        if (!Visited[W->Vertex])
            DFS(W->Vertex);
    }
}

// Initialize visited and graph arrays
void Initialize() {
    for (int i = 0; i < N; i++) {
        Graph[i] = NULL;
        Visited[i] = FALSE;
    }
}

int main() {
    int Edges, Src, Dest, StartVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &N);

    Initialize();

    printf("Enter number of edges: ");
    scanf("%d", &Edges);

    printf("Enter each edge (source destination):\n");
    for (int i = 0; i < Edges; i++) {
        scanf("%d %d", &Src, &Dest);
        AddEdge(Src, Dest);
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &StartVertex);

    printf("\nDepth First Search Traversal:\n");
    DFS(StartVertex);
    printf("\n");

    return 0;
}
