#include<stdio.h>

#define MAX 5

typedef struct{
	int arr[MAX];
	int front, rear;
}QueueArr;

typedef struct node{
	int data;
	struct node* link;
}Node;

typedef struct {
	Node* front;
	Node* rear;
}Queue;



int isEmptyStack(stack s);


int main(){
	
}


//1. Implement a function to check if the stack is empty in an array-based stack.
int isEmptyStack(stack s){
	return(s.top == -1)?1:0;
}

//2. Write a function to enqueue an element in an array-based queue.

void enqueue(QueueArr *Q, int value){
	if(Q->rear+1%MAX == Q->front){
		printf("Empty.");
	}else{
		Q->rear = Q->rear+1 % MAX;
		Q->arr[Q->front] = value;
	}
}

vectorSet intersection(vectorSet C, vectorSet A){
	vectorSet B = malloc(sizeof(struct node));
	if()
}
