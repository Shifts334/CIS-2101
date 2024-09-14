#include<stdio.h>
#include<stdlib.h>

#define MAX 10

//queue definition
typedef struct stack{
    int dataArr[MAX];
    int top;
}stack;

//prototypes
void initialize(stack *s);
void push(stack *s, int data);
void pop(stack *s);
int isEmpty(stack s);
int isFull(stack s);
void peek(stack s);
void display(stack s);

//driver function
void main(){
    stack test;
    initialize(&test);
    push(&test, 10);
    push(&test, 20);
    push(&test, 30);
    display(test);
    pop(&test);
    peek(test);
    push(&test, 40);
    display(test);

}

//function definitions
void initialize(stack *s){
    s->top = -1;
}

void push(stack* s, int elem){
    if(isFull(*s)){
        printf("\nStack is full\n");
    }
    else{
        s->dataArr[++s->top] = elem;
    }
}

void pop(stack *s){
    if(isEmpty((*s))){
        printf("\nStack i1s empty.");
    }
    else{
        printf("\nElement popped: %d", s->dataArr[s->top--]);
    }
}

int isEmpty(stack s){
    return(s.top == -1)?1:0;
}

int isFull(stack s){
    return(s.top == MAX-1)?1:0;
}

void peek(stack s){
    if(isEmpty(s)){
        printf("\nStack is empty\n");
    }
    else{
        printf("\nelement peek: %d\n",s.dataArr[s.top]);
    }
}

void display(stack s){
    if(isEmpty(s)){
        printf("\nStack is empty.");
    }
    else{
        printf("Display: ");
        for(int i = s.top; i>=0; i--){
            printf("%d ", s.dataArr[i]);
        }
    }
}