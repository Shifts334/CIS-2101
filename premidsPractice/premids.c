#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} *linklist;

void enqueue(linklist *q, int value);
int dequeue(linklist *q);
int peek(linklist *q);
void display(linklist *q);


int main() {
    linklist queue = NULL;  // Initializing the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    display(&queue);  // Should display 10 20 
    printf("Front element: %d\n", peek(&queue));//Should print 10 
    dequeue(&queue);
    printf("Queue after dequeue: ");
    display(&queue);  // Should display 20 30
    return 0;
}


void enqueue(linklist *q, int value){
    linklist temp, r;
    temp = (linklist)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if(*q == NULL){
        *q = temp;
    }else{
        r = *q;
        while(r->next != NULL){
            r = r->next;
        }
        r->next = temp;
    }
}

int dequeue(linklist *q){
    linklist temp;
    if(*q == NULL){
        printf("Queue is empty\n");
    }else{
        temp = *q;
        *q = (*q)->next;
        free(temp);
    }
}

int peek(linklist *q){
    if(*q == NULL){
        printf("Queue is empty\n");
    }else{
        return (*q)->data;
    }
}

void display(linklist *q){
    linklist temp;
    temp = *q;
    if(temp == NULL){
        printf("Queue is empty\n");
    }else{
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

