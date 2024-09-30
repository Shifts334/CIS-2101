#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5

//array definition of stack
typedef struct{
	int arr[MAX]; // array
	int top; //index of top element
}Stack;

// linked list definition of stack
typedef struct node{
	int data;
	struct node* link;
}Top, *Topptr;

//prototypes for Array
bool isEmpty(Stack *s);
bool isFull(Stack *s);
void pushArray(Stack* s, int new_data);
void popArray(Stack* s);

//prototypes for LinkedLists
bool isEmptyLL(Topptr n);
void pushLL(Topptr *s, int new_data);
void popLL(Topptr *s);

//main Function
int main(){
	
}

// function definitions for Array Implementation
bool isEmpty(Stack *arr){
	return(arr->top == NULL)?1:0;
}
bool isFull(Stack *arr){
	return(arr->top == MAX-1)?1:0;
}

void pushArray(Stack *s, int new_data){
	if(isFull(s)){
		printf("Full.");
	}else{
		s->top ++;
		s->arr[s->top] = new_data; // add new data as per usual
	}
}

void popArray(Stack *s){
	if(isEmpty(s)){
		printf("Empty.");
	}else{
		s->arr[s->top] = 0; //operation to return it or whatever is required
		s->top--;
	}
}

// function defintions for Linked List Implementation
bool isEmptyLL(Topptr n){
	return(n == NULL)?1:0;
}

void pushLL(Topptr* s, int new_data){
	Topptr newNode = (Topptr)malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Memory allocation failed.");
		return;
	}
	newNode->data = new_data;
	newNode->link = *s;
	*s = newNode;
}

void popLL(Topptr *s){
	if(isempty(*s)){
		printf("Empty.");
	}else{
		Topptr temp = s;
		s = temp->link;
		free(temp);
	}
}


