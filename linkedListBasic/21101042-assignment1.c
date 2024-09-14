#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_CARS 100
#define CAR_ID_LENGTH 6


//Node Structure for the Queue: 
typedef struct node {
    char action[5]; // Action to perform: "push" (return car) or "pop" (rent car)
    char customerName[100]; // Customer's name
    char carId[CAR_ID_LENGTH]; // Car ID that the customer rented, empty if not rented
    struct node* next; // Pointer to the next node in the queue
} Node;

// Stack Structure for Car IDs:
typedef struct {
    char carIds[MAX_CARS][CAR_ID_LENGTH]; // Array to hold car IDs contiguously
    int top; // Index of the top element in the stack
} CarStack;

//Queue Structure:
typedef struct Queue{
    Node* front; // Pointer to the front of the queue
    Node* rear; // Pointer to the rear of the queue
} *Queue;

//PROTOTYPES
bool isCarStackEmpty (CarStack* stack);
bool isCarStackFull (CarStack* stack);
bool isQueueEmpty (Queue q);

//Queue prototypes
Queue createQueue();
void enqueue (Queue q, const char* action, const char* customerName, const char* carId);
struct node* dequeue (Queue q);

//Stack prototypes
void initializeCarStack(CarStack* s);
void pushCar(CarStack* carStack, const char* string) {
    if (isCarStackFull(carStack)) { // Corrected line
        printf("Car stack is full. Cannot push %s\n", string);
        return;
    }
    strcpy(carStack->carIds[++carStack->top], string);
}

char* popCar(CarStack* carStack) {
    if (isCarStackEmpty(carStack)) { // Corrected line
        printf("Car stack is empty. Cannot pop.\n");
        return NULL;
    }
    return carStack->carIds[carStack->top--];
}

//display prototypes
void displayCarStack(CarStack carStack);
void displayQueue (Queue q);

int main(){
    //initialize shit
    Queue customerQueue = createQueue();
    CarStack carStack;
    initializeCarStack(&carStack);

    //Queue
    enqueue(customerQueue, "pop", "Alice", "");
    enqueue(customerQueue, "pop", "Charlie", "");
    enqueue(customerQueue, "push", "Bob", "Ca999");
    enqueue(customerQueue, "push", "Andy", "Ca439");
    enqueue(customerQueue, "pop", "Robert", "");
    
    //stack
    pushCar(&carStack, "Ca123");
    pushCar(&carStack, "Ca456");
    pushCar(&carStack, "Ca789");
    pushCar(&carStack, "Ca439");
    pushCar(&carStack, "Ca956");
    pushCar(&carStack, "Ca829");

    printf("Initial Stack\n");
    displayCarStack(carStack);
    printf("\nInitial Queue\n");
    displayQueue(customerQueue);
    
    for (Node* temp = customerQueue->front; temp; temp = temp->next) {
        Node* nodeToFree = dequeue(customerQueue);
        if (strcmp(temp->action, "push") == 0) {
            pushCar (&carStack, temp->carId);
        } else if (strcmp(temp->action, "pop") == 0) {
            char* poppedCarId = popCar(&carStack);
            strcpy (temp->carId, poppedCarId);
        }
        free (nodeToFree);
    }
    
    printf("\nNew Stack\n");
    displayCarStack(carStack);
    printf("\nNew Queue\n");
    displayQueue(customerQueue);

    free(customerQueue);
}

//FUNCTIONS

//Queue Functions
Queue createQueue(){//Description: Initializes a new queue by allocating memory and setting the front and rear pointers to NULL.
    Queue line = malloc(sizeof(Queue));
    line->front = NULL;
    line->rear = NULL;
    return line;
}

void enqueue(Queue q, const char *action, const char *customerName, const char*carId){ //Description: Adds a new action (rent or return) to the end of the queue. It creates a new node, sets its action, customer name, and carId, and updates the rear pointer.
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->action, action);
    strcpy(newNode->carId, carId);
    strcpy(newNode->customerName, customerName);
    newNode->next = NULL;
    
    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    
    q->rear->next = newNode;
    q->rear = newNode;
}

struct node* dequeue (Queue q){ //Description: Removes and returns the action node from the front of the queue. Updates the front pointer to the next node. If the queue becomes empty, the rear pointer is also set to NULL.
    Node* temp = q->front;
    
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
        temp = q->front;
    } else {
        q->front = q->front->next;
    }
    return temp;
}

bool isQueueEmpty(Queue q){ //Description: Checks if the queue is empty by verifying if the front pointer is NULL.
    return (q->front == NULL) ? true : false;
}

// Stack Functions
void initializeCarStack(CarStack* s){ //Description: Initializes the stack by setting the top index to -1, indicating that the stack is empty.
    s->top = -1;
}
void pushCar (CarStack* carStack, const char* string){ //Description: Adds a car ID to the top of the stack. It checks if the stack is full before adding the ID and updates the top index. Returns 1 if push was successfull
     if (isCarStackFull(carStack->top)) {
         printf("Stack Overflow!");
         return;
     } 
     
    carStack->top++;
    strcpy(carStack->carIds[carStack->top], string);    
}
char* popCar(CarStack* s){ //Description: Removes and returns the car ID from the top of the stack. It checks if the stack is empty before removing the ID and updates the top index.
    char* temp = (char*)malloc(CAR_ID_LENGTH * sizeof(char));
    if (isCarStackEmpty(s->top)) {
        printf("Error!");
    } else {
        strcpy(temp, s->carIds[s->top]);
        s->top--;
        return temp;
    }
}
bool isCarStackEmpty (CarStack* stack){ //Description: Checks if the stack is empty by verifying if the top index is -1.
    return(stack->top == -1)?true:false;
}
bool isCarStackFull (CarStack* stack){ //Description: Checks if the stack is full by comparing the top index with MAX_CARS - 1
    return(stack->top == MAX_CARS - 1)?true:false;
}

void displayQueue(Queue q){
    Node* temp = q->front;
    for (;temp; temp = temp->next) {
        printf("%s ",temp->action);
        printf("%s ",temp->customerName);
        printf("%s\n",temp->carId);
    }
}
void displayCarStack(CarStack carStack){
    int i;
    for (i = carStack.top; i >= 0; i--) {
        printf("Stack String: ");
        printf("%s\n",carStack.carIds[i]);
    }
}