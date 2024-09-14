#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    char position;
    struct node* link;
}list, *listPtr;

void insertFirst(listPtr*, char elem);
void insertLast(listPtr*);
void insertMid(listPtr*);
void printList(listPtr);
void insertPos(listPtr*, char elem, char inserPos);
void displayList(listPtr);



int main(){
    listPtr head = (listPtr)malloc(sizeof(list));
    listPtr second = (listPtr)malloc(sizeof(list));
    listPtr third = (listPtr)malloc(sizeof(list));

    if (head == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    head->position = 'A';
    head->link = second;
    second->position = 'B';
    second->link = third;
    third->position = 'C';
    third->link = NULL;

    printf("Original List: ");
    displayList(head);

    char newPos = 'D';
    char inserPos = 'B'; 

    // Assuming insertPos is defined elsewhere and works correctly
    // insertPos(&head, newPos, inserPos);

    insertFirst(&head, newPos);
    insertPos(&head, newPos, inserPos);
    printf("Updated List: ");
    displayList(head);

    // Free allocated memory
    free(third);
    free(second);
    free(head);
}

void insertFirst(listPtr* head, char newPos){
    listPtr new = malloc(sizeof(struct node));
    new->position = (*head)->position;
    new->link = (*head)->link;
    head = &new;
}

void insertPos(listPtr* head, char elem, char inserPos){
    listPtr new = malloc(sizeof(struct node));
    new->position = elem;
    new->link = NULL;
    listPtr temp = *head;
    while(temp->position != inserPos){
        temp = temp->link;
    }
    new->link = temp->link;
    temp->link = new;
}

void displayList(listPtr head){
    listPtr temp = head;
    while(temp != NULL){
        printf("%c ", temp->position);
        temp = temp->link;
    }
    printf("\n");
}