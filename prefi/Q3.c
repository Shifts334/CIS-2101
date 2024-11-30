#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Structure to represent an element with a priority
typedef struct {
    int value;
    int priority;
} Element;

// Circular priority queue structure
typedef struct {
    Element arr[SIZE];
    int front;
    int rear;
    int count;
} CircularPriorityQueue;

// Initialize the queue
void initQueue(CircularPriorityQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Check if the queue is full
int isFull(CircularPriorityQueue* q) {
    return q->count == SIZE;
}

// Check if the queue is empty
int isEmpty(CircularPriorityQueue* q) {
    return q->count == 0;
}

// Enqueue function (insertion based on priority)
void enqueue(CircularPriorityQueue* q, int value, int priority) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    // Find the correct position for the new element
    int i = q->rear;
    while (q->count > 0 && i != q->front - 1 && q->arr[(i + SIZE) % SIZE].priority > priority) {
        q->arr[(i + 1 + SIZE) % SIZE] = q->arr[i];
        i = (i - 1 + SIZE) % SIZE;
    }

    // Insert the new element at the found position
    q->arr[(i + 1 + SIZE) % SIZE].value = value;
    q->arr[(i + 1 + SIZE) % SIZE].priority = priority;
    q->rear = (q->rear + 1) % SIZE;
    q->count++;
}

// Dequeue function (removal of highest priority element)
void dequeue(CircularPriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    // Remove the element from the front of the queue
    printf("Dequeued element: %d with priority: %d\n", q->arr[q->front].value, q->arr[q->front].priority);
    q->front = (q->front + 1) % SIZE;
    q->count--;
}

// Display the elements in the queue
void displayQueue(CircularPriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements:\n");
    for (int i = 0, index = q->front; i < q->count; i++) {
        printf("Value: %d, Priority: %d\n", q->arr[index].value, q->arr[index].priority);
        index = (index + 1) % SIZE;
    }
}

int main() {
    CircularPriorityQueue q;
    initQueue(&q);

    // Insert elements
    enqueue(&q, 10, 2);
    enqueue(&q, 20, 1);
    enqueue(&q, 30, 3);
    enqueue(&q, 40, 0);
    enqueue(&q, 50, 5);

    // Display the queue
    displayQueue(&q);

    // Remove elements (dequeue)
    dequeue(&q);
    displayQueue(&q);

    dequeue(&q);
    displayQueue(&q);

    return 0;
}

