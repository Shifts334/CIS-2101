#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node{
    int data;
    struct node *next;
    int front;
    int rear;
}node;

typedef struct queue{
	int front;
	int rear;
}queue;

//prototypes
void initialQ(queue *line);
int isFull(queue *line);
int isEmpty(queue *line);
void enqueue(); //Rear
void dequeue(); //Front


//main function
int main(){
	queuePtr Qline;
	
}

void initialQ(queue *line){
	line->front = line->rear = -1;
}

int isFull(queue *line){
	if((line->rear) == MAX -1){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(queue *line){
	if((line->front) == -1){
		return 1;
	}else{
		return 0;
	}
}




