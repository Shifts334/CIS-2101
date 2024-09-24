#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node{
    int data;
    struct node *next;
    int front;
    int rear;
}Node, *NodePtr;

typedef struct queue{
	NodePtr front, rear;
}Queue, *QueuePtr;

//prototypes
QueuePtr initialQ(); // the same as creating a queue
Node createNode(int data);
int isFull(QueuePtr);
int isEmpty(QueuePtr);
void enqueue(); //Rear
void dequeue(); //Front


//main function
int main(){
	QueuePtr line = initialQ();
	
}

QueuePtr initialQ(){
	
	QueuePtr newQueue = malloc(sizeof(Queue));
	newQueue->front = newQueue->rear = -1;
	return newQueue;
}

Nodeptr createNode(int new_data){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	newNode->data = new_data;
	newNode->next = NULL;
}

int isFull(QueuePtr line){
	if((line->rear) == MAX -1){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(QueuePtr line){
	if((line->front) == -1){
		return 1;
	}else{
		return 0;
	}
}

void enqueue(queue)




