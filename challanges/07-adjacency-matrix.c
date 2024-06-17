#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int adjacencyMatrix[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;

// Function to enqueue a node into the queue
void enqueue(int node)
{
    if (rear == MAX_NODES - 1) {
	printf("Queue overflow\n");
	return;
    }
    if (front == -1) {
	front = 0;
    }
    queue[++rear] = node;
}

// Function to dequeue a node from the queue
int dequeue()
{
    if (front == -1 || front > rear) {
	printf("Queue underflow\n");
	return -1;
    }
    int node = queue[front++];
    if (front > rear) {
	front = rear = -1;	// Reset queue
    }
    return node;
}

// Function to perform breadth-first search (BFS)
void BFS(int start, int numNodes)
{
    enqueue(start);
    visited[start] = true;

    while (front != -1) {
	int currentNode = dequeue();
	if (currentNode == -1) {
	    break;
	}
	printf("%d ", currentNode);

	for (int i = 0; i < numNodes; ++i) {
	    if (adjacencyMatrix[currentNode][i] && !visited[i]) {
		enqueue(i);
		visited[i] = true;
	    }
	}
    }
}

int main()
{
    int numNodes, sourceNode;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", numNodes, numNodes);
    for (int i = 0; i < numNodes; ++i) {
	for (int j = 0; j < numNodes; ++j) {
	    scanf("%d", &adjacencyMatrix[i][j]);
	}
    }

    // Initialize visited array
    for (int i = 0; i < numNodes; ++i) {
	visited[i] = false;
    }

    // Input the source node for BFS
    printf("Enter the source node for BFS: ");
    scanf("%d", &sourceNode);

    // Perform BFS
    printf("BFS Traversal: ");
    BFS(sourceNode, numNodes);
    printf("\n");

    return 0;
}
