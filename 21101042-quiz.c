#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CARS 100
#define CAR_ID_LENGTH 6
#define carIDLENGTH 100*6

//1. Node Structure for the Queue
// Node structure for the queue (linked list)
struct Node {
    char action[5];          // Action to perform: "push" (return car) or "pop" (rent car)
    char customerName[100];  // Customer's name
    struct Node* next;       // Pointer to the next node in the queue
};

//2. Stack Structure for Car IDs
// Stack structure implemented using a single-dimensional array
typedef struct {
    char carIds[MAX_CARS * CAR_ID_LENGTH]; // Array to hold car IDs contiguously
    int top;                // Index of the top element in the stack
} CarStack;

//3. Queue Structure
// Queue structure with pointers to the front and rear
typedef struct {
    struct Node *front;     // Pointer to the front of the queue
    struct Node *rear;      // Pointer to the rear of the queue
} *Queue;

//prototypes
void initializeCarStack(CarStack* s);
void pushCar(CarStack* s, const char *carId);
int isCarStackEmpty(CarStack* s);
int isCarStackFull(CarStack* s);
int isFull(int top);
int isEmpty(CarStack stack);



int main(){
	//queue
//	Queue customerQueue = createQueue();
//	enqueue(customerQueue, "pop", "Alice");
//	enqueue(customerQueue, "pop", "Charlie");
//	enqueue(customerQueue, "push", "Bob"); 
//	enqueue(customerQueue, "push", "Andy"); 
//	enqueue(customerQueue, "pop", "Robert");

	//stack
	CarStack carStack; 
	initializeCarStack(&carStack);
	pushCar(&carStack, "Ca123");
	pushCar(&carStack, "Ca456");
	pushCar(&carStack, "Ca789");
	pushCar(&carStack, "Ca439");
	pushCar(&carStack, "Ca956");
	pushCar(&carStack, "Ca829");
	
	printf("%s\n", carStack.carIds);
	printf("%d", carStack.top);
	
//	free(customerQueue);
}

//FUNCTIONS


//Queue
Queue createQueue(){//Description: Initializes a new queue by allocating memory and setting the front and rear pointers to NULL.
	Queue line = malloc(sizeof(struct Node));
}
void enqueue(Queue q, char *action, char *customerName){ //Description: Adds a new action (rent or return) to the end of the queue. It creates a new node, sets its action and customerName, and updates the rear pointer.

}
struct Node* dequeue(Queue q){ //Description: Removes and returns the action node from the front of the queue. Updates the front pointer to the next node. If the queue becomes empty, the rear pointer is also set to NULL.

}
int isQueueEmpty(Queue q){ //Description: Checks if the queue is empty by verifying if the front pointer is NULL.

}



//Stack
void initializeCarStack(CarStack* s){ //Description: Initializes the stack by setting the top index to -1, indicating that the stack is empty.
	s->top = -1;
}
void pushCar(CarStack* s, const char *carId){ //Description: Adds a car ID to the top of the stack. It checks if the stack is full before adding the ID and updates the top index.
	if(isCarStackFull(s)){
		printf("Stack is full");
	}if(isCarStackEmpty(s)){
		strcpy(s->carIds,carId);
		s->top += 6;
	}else{
		strcat(s->carIds," ");
		strcat(s->carIds,carId);
		s->top += 6;
	}
}
char* popCar(CarStack* s){ //Description: Removes and returns the car ID from the top of the stack. It checks if the stack is empty before removing the ID and updates the top index.
	if(isCarStackEmpty(s)){
		printf("It's empty");
	}
	else{
		
	}
}
int isCarStackEmpty(CarStack* s){ //Description: Checks if the stack is empty by verifying if the top index is -1.
	if(s->top == -1){
		return 1;
	}else{
		return 0;
	}
}
int isCarStackFull(CarStack* s){ //Description: Checks if the stack is full by comparing the top index with MAX_CARS - 1
	if(s->top == MAX_CARS - 1){
			return 1;
		}else{
			return 0;
		}
}

