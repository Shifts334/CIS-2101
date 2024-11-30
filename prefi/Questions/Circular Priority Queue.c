#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Fixed size of the circular queue

typedef struct {
    int data;       // The data stored in the queue
    int priority;   // The priority of the data (higher is higher priority)
} Element;

typedef struct {
    Element queue[MAX_SIZE]; // Circular array to store the elements
    int front;               // Index of the front of the queue
    int rear;                // Index of the rear of the queue
    int size;                // Current size of the queue
} CircularPriorityQueue;

// Initialize the queue
void init_queue(CircularPriorityQueue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// Check if the queue is full
int is_full(CircularPriorityQueue* q) {
	return q->size == MAX_SIZE;
}

// Check if the queue is empty
int is_empty(CircularPriorityQueue* q) {
	return q->size == 0;
}

// Enqueue an element into the circular priority queue
void enqueue(CircularPriorityQueue* q, int data, int priority) {
	if (is_full(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    Element newElement = {data, priority};

    if (is_empty(q)) {
        // If the queue is empty, initialize front and rear
        q->front = 0;
        q->rear = 0;
        q->queue[q->rear] = newElement;
    } else {
        // Find the appropriate position for the new element based on priority
        int i = q->rear;
        while (i != (q->front - 1 + MAX_SIZE) % MAX_SIZE && 
               q->queue[i].priority < priority) {
            q->queue[(i + 1) % MAX_SIZE] = q->queue[i];
            i = (i - 1 + MAX_SIZE) % MAX_SIZE;
        }
        q->queue[(i + 1) % MAX_SIZE] = newElement;
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->size++;
}

// Dequeue the highest-priority element
Element dequeue(CircularPriorityQueue* q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return (Element){-1, -1}; // Return an invalid element
    }

    Element dequeuedElement = q->queue[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;

    if (q->size == 0) {
        // Reset the queue when it becomes empty
        q->front = -1;
        q->rear = -1;
    }

    return dequeuedElement;
}

// Print the elements of the queue (from front to rear)
void print_queue(CircularPriorityQueue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (priority order): ");
    int i = q->front;
    int count;
    for (count = 0; count < q->size; count++) {
        printf("[Data: %d, Priority: %d] ", q->queue[i].data, q->queue[i].priority);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    CircularPriorityQueue q;
    init_queue(&q);

    // Enqueue some elements with different priorities
    enqueue(&q, 10, 3); // Data: 10, Priority: 3
    enqueue(&q, 20, 5); // Data: 20, Priority: 5
    enqueue(&q, 30, 2); // Data: 30, Priority: 2
    enqueue(&q, 40, 8); // Data: 40, Priority: 8
    enqueue(&q, 50, 1); // Data: 50, Priority: 1

    // Print the queue
    print_queue(&q);

    // Dequeue the highest-priority element
    Element dequeued_element = dequeue(&q);
    printf("Dequeued element: Data = %d, Priority = %d\n", dequeued_element.data, dequeued_element.priority);

    // Print the queue again after dequeue
    print_queue(&q);

    return 0;
}
