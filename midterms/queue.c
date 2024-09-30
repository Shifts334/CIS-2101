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
}Node, *NodePtr;
typedef struct{
	NodePtr front, rear;
}QueueLL;


//prototypes of Array implementation
QueueArray createQarr();
bool isFullArr(QueueArray *a);
bool isEmptyArr(QueueArray *a);
void enqueueArr(QueueArray *a, int new_data);
void dequeueArr(QueueArray *a);

//prototypes of Linked List implementation 
bool isFullLL(QueueLL a)

//main Function
int main(){
	
}



//function definition of array functions
QueueArray createQarr(){
	QueueArray q;
	q.front = 0;
	q.rear = MAX-1;
	return q;
}

bool isFull(QueueArray *a){
	return(a->rear+2)%MAX == a->front;
}

bool isEmpty(QueueArray *a){
	return(a->rear+1)%MAX == a->front;
}

void enqueueArr(QueueArray *a, int new_data){

}

//function definition of linked list implementation
