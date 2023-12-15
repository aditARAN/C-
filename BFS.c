#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list for each vertex
struct Graph {
    int vertices;
    struct Node** adjacencyList;
    int* visited;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node*)malloc(vertices* sizeof(struct Node));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

// Function to perform Breadth-First Search
void BFS(struct Graph* graph, int startVertex) {
    struct Node* temp;
    int currentVertex;

    // Create a queue for BFS
    int queue[graph->vertices];
    int front = -1, rear = -1;

    // Mark the current node as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        // Dequeue a vertex from the queue
        currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex is not visited, mark it visited and enqueue it
        temp = graph->adjacencyList[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

// Driver program to test the functions
int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Breadth-First Traversal starting from vertex 0: ");
    BFS(graph, 0);

    return 0;
}