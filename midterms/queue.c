#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5

//Queue structure for Array 
typedef struct{
	int arr[MAX];
	int front, rear;
}QueueArray;

//Queue structure for Linked List
typedef struct node {
	int data;
	struct node* link;
}*NodePtr;
typedef struct{
	NodePtr front, rear;
}QueueLL;


//prototypes of Array implementation
void createQarr();
bool isFullArr(QueueArray *a);
bool isEmptyArr(QueueArray *a);
void enqueueArr(QueueArray *a, int new_data);
void dequeueArr(QueueArray *a);

//prototypes of Linked List implementation 
QueueLL createQLL();
bool isFullLL(QueueLL *b);
bool isEmptyLL(QueueLL b);
void enqueueLL(QueueLL *b, int new_data);
void dequeueLL(QueueLL *b);

//main Function
int main(){
	
}



//function definition of array functions
void createQarr(){
	q->front = 0;
	q->rear = MAX-1;
	return q;
}

bool isFullArr(QueueArray *a){
	return(a->rear+2)%MAX == a->front;
}

bool isEmptyArr(QueueArray *a){
	return(a->rear+1)%MAX == a->front;
}

void enqueueArr(QueueArray *a, int new_data){
	if(isFullArr(*a)){
		printf("Queue Overflow");
		return;
	}else{
		a->rear = (a->rear+1)%MAX;
		a->arr[a->rear] = new_data;
	}
}

void dequeueArr(QueueArray *a){
	if((*a->rear+2)%MAX == a->front){
		printf("Empty.");
		return;
	}else{
		a->front = (a->front+1) % MAX;
	}
}


//function definition of linked list implementation
void createQLL(){
	QueueLL newQ;
	newQ->front = NULL;
	newQ->rear = NULL;
}

bool isEmptyLL(QueueLL b){
	return (b->front == NULL && b->rear == NULL)?1:0;
}

bool isFull(QueueLL b){
	
}

void enqueueLL(QueueLL *b, int new_data){
	
	if()
}


