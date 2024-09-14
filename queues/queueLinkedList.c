#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int data;
    struct queue *next;
}queue, *queuePtr;

//prototypes 