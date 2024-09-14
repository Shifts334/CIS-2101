#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}ListV1, *ListV2;

typedef struct{
    int * elemPtr;
    int count;
    int ArrSize;
}ListV3, *ListV4;

void initializeV1(ListV1 * L){
    L->count = 0;
}

void initializeV2(ListV2 L){
    if(L!=NULL){
        L->count=0;
    }
}

void initializeV3(ListV3 * L){
    L->elemPtr=(int*)malloc(MAX * sizeof(int));
    L->count=0;
    L->ArrSize=MAX;
}

void initializeV4(ListV4 L){
    L->elemPtr=(int*)malloc(MAX * sizeof(int));
    L->count = 0;
    L->ArrSize=MAX;
}


void populateListV1(ListV1 * L){
    int temp[]={1,2,3,4,5};
    memcpy(L->elem,temp,5*sizeof(int));
    L->count=5;
}

void populateListV2(ListV2 L){
    int temp[]={6,7,8,9,10};
    memcpy(L->elem,temp,5*sizeof(int));
    L->count=5;
}

void populateListV3(ListV3 * L){
    if(L->elemPtr!=NULL){
        int temp[]={11,12,13,14,15};
        memcpy(L->elemPtr,temp,5*sizeof(int));
        L->count=5;
    }
}

void populateListV4(ListV4 L){
    if(L->elemPtr!=NULL){
        int temp[]={16,17,18,19,20};
        memcpy(L->elemPtr,temp,5*sizeof(int));
        L->count=5;
    }
}

void insertV1(int elem, int pos, ListV1 * L){
    int i;
    for(i=L->count;i>=pos;i--){
        L->elem[i]=L->elem[i-1];
    }
    L->elem[pos-1]=elem;
    L->count++;
}

void insertV2(int elem, int pos, ListV2 L){
    int i;
    for(i=L->count;i>=pos;i--){
        L->elem[i]=L->elem[i-1];
    }
    L->elem[pos-1]=elem;
    L->count++;
}

void insertV3(int elem,int pos, ListV3 * L){
    int i;
    if(L->elemPtr!=NULL){
        for(i=L->count;i>=pos;i--){
            L->elemPtr[i]=L->elemPtr[i-1];
        }
        L->elemPtr[pos-1]=elem;
        L->count++;
    }
}

void insertV4(int elem, int pos, ListV4 L){
    int i;
    if(L->elemPtr!=NULL){
        for(i=L->count;i>=pos;i--){
            L->elemPtr[i]=L->elemPtr[i-1];
        }
        L->elemPtr[pos-1]=elem;
        L->count++;
    }
}

void deletePosV1(int pos, ListV1 * L){
    int i;
    if(pos>0 && pos<=MAX){
        for(i=pos-1;i<L->count;i++){
        L->elem[i]=L->elem[i+1];
        }
    }
    L->count--;
}

void deletePosV2(int pos, ListV2 L){
    int i;
    if(pos>0 && pos<=MAX){
        for(i=pos-1;i<L->count;i++){
        L->elem[i]=L->elem[i+1];
        }
    }
    L->count--;
}

void deletePosV3(int pos, ListV3 * L){
    int i;
    if(pos>0 && pos<=MAX){
        for(i=pos-1;i<L->count;i++){
            L->elemPtr[i]=L->elemPtr[i+1];
        }
        L->count--;
    }
}

void deletePosV4(int pos, ListV3 * L){
    int i;
    if(pos>0 && pos<=MAX){
        for(i=pos-1;i<L->count;i++){
            L->elemPtr[i]=L->elemPtr[i+1];
        }
        L->count--;
    }
}

int locateV1(int elem, ListV1 * L){
    int i;
    for(i=0;i<L->count && L->elem[i]!=elem;i++){}
    return (i<L->count) ? (i+1):0;
}

int locateV2(int elem, ListV2 L){
    int i;
    for(i=0;i<L->count && L->elem[i]!=elem;i++){}
    return (i<L->count) ? (i+1):0;
}

int locateV3(int elem, ListV3 * L){
    int i;
    for(i=0;i<L->count && L->elemPtr[i] != elem; i++){}
    return (i<L->count) ? (i+1):0;
}

int locateV4(int elem, ListV4 L){
    int i;
    for(i=0;i<L->count && L->elemPtr[i] != elem; i++){}
    return (i<L->count) ? (i+1):0;
}

int retrieveV1(int pos, ListV1 * L){
    int ret = 0;
    if(pos<L->count){
        ret = L->elem[pos-1];
    } 
    return ret;
}

int retrieveV2(int pos, ListV2 L){
    int ret = 0;
    if(pos<L->count){
        ret=L->elem[pos-1];
    }
    return ret;
}

int retrieveV3(int pos, ListV3 * L){
    int ret = 0;
    if(pos<L->count){
        ret=L->elemPtr[pos-1];
    }
    return ret;
}

int retrieveV4(int pos, ListV4 L){
    int ret = 0;
    if(pos<L->count){
        ret=L->elemPtr[pos-1];
    }
    return ret;
}

void printListV1(ListV1 L){
    int i;
    if(L.count>0){
        for(i=0;i<L.count;i++){
        printf("%d ", L.elem[i]);
    }
    } else {
        printf("The list is NULL.");
    }
}

void printListV2(ListV2 L){
    int i;
    if(L!=NULL){
        for(i=0;i<L->count;i++){
        printf("%d ", L->elem[i]);
    }
    }else {
        printf("The list is NULL.");
    }
    
}

void printListV3(ListV3 L){
    int i;
    if(L.count>0){
    for(i=0;i<L.count;i++){
        printf("%d ", L.elemPtr[i]);
    }}
    else {
        printf("The list is NULL.");
    }
}

void printListV4(ListV4 L){
    int i;
    if(L!=NULL){
    for(i=0;i<L->count;i++){
            printf("%d ", L->elemPtr[i]);
        }
    } else {
        printf("The list is NULL.");
    }
}
    
void makeNullV1(ListV1 * L) {
    L->count = 0;
}

void makeNullV2(ListV2 * L) {
    if (*L != NULL) {
        free(*L);
        *L = NULL;
    }
}

void makeNullV3(ListV3 * L) {
    if (L != NULL && L->elemPtr != NULL) {
        free(L->elemPtr); 
        L->elemPtr = NULL; 
    }
    L->count = 0;         
}

void makeNullV4(ListV4 * L) {
    if (*L != NULL) {
        if ((*L)->elemPtr != NULL) {
            free((*L)->elemPtr);
            (*L)->elemPtr = NULL;
        }
        free(*L);
        *L = NULL;
    }
}


int main(){
    //LIST VERSION 1
    ListV1 L1;
    initializeV1(&L1);
    populateListV1(&L1);
    int i;
    //populate
    printf("Original V1 List: ");
    printListV1(L1);
    printf("\n");
    //insert
    insertV1(9,3,&L1);
    printf("Inserted V1 List: ");
    printListV1(L1);
    //delete
    printf("\nDeleted Pos V1 List: ");
    deletePosV1(2,&L1);
    printListV1(L1);
    //locate
    printf("\n");
    int pos1=locateV1(4,&L1);
    if(pos1>0)
    {
        printf("The Location of 4 is found in: %d", pos1);
    } else {
        printf("There is no element found.");
    }
    //retrieve
    int ret1=retrieveV1(2,&L1);
    if(ret1>0)
    {
        printf("\nThe element on position 3 is: %d", ret1);
    } else {
        printf("\nPosition isn't valid.");
    }
    printf("\n\n");


    



    //LIST VERSION 2
    ListV2 L2=(ListV2)malloc(sizeof(ListV1));
    initializeV2(L2);
    populateListV2(L2);
    //populate
    printf("Original V2 List: ");
    printListV2(L2);
    //insert
    printf("\n");
    insertV2(999,3,L2);
    printf("Inserted V2 List: ");
    printListV2(L2);
    //delete
    printf("\nDeleted Pos V2 List: ");
    deletePosV2(2,L2);
    printListV2(L2);
    //locate
    printf("\n");
    int pos2=locateV2(10, L2);
    if(pos2>0)
    {
        printf("The Location of 10 is found in: %d", pos2);
    } else {
        printf("There is no element found.");
    }
    //retrieve
    int ret2=retrieveV2(2,L2);
    if(ret2>0)
    {
        printf("\nThe element on position 2 is: %d", ret2);
    } else {
        printf("\nPosition isn't valid.");
    }
    printf("\n\n");






    //LIST VERSION 3
    ListV3 L3;
    initializeV3(&L3);
    populateListV3(&L3);
    //populate;
    printf("Original V3 List: ");
    printListV3(L3);
    //insert
    printf("\n");
    insertV3(888,1,&L3);
    printf("Inserted V3 List: ");
    printListV3(L3);
    //delete
    printf("\nDeleted Pos V3 List: ");
    deletePosV3(1,&L3);
    printListV3(L3);
    //locate
    printf("\n");
    int pos3=locateV3(12, &L3);
    if(pos3>0)
    {
        printf("The Location of 12 is found in: %d", pos3);
    } else {
        printf("There is no element found.");
    }
    //retrieve
    int ret3=retrieveV3(4,&L3);
    if(ret3>0)
    {
        printf("\nThe element on position 4 is: %d", ret3);
    } else {
        printf("\nPosition isn't valid.");
    }
    printf("\n\n");



    //LIST VERSION 4
    ListV4 L4=(ListV4)malloc(sizeof(ListV3));
    initializeV4(L4);
    populateListV4(L4);
    //populate
    printf("Original V4 List: ");
    printListV4(L4);
    //insert
    printf("\n");
    insertV4(1111,2,L4);
    printf("Inserted V4 List: ");
    printListV4(L4);
    //delete
    printf("\nDeleted Pos V4 List: ");
    deletePosV4(5,L4);
    printListV4(L4);
    //locate
    printf("\n");
    int pos4=locateV4(18, L4);
    if(pos4>0)
    {
        printf("The Location of 18 is found in: %d", pos4);
    } else {
        printf("There is no element found.");
    }
    //retrieve
    int ret4=retrieveV4(2, L4);
    if(ret4>0)
    {
        printf("\nThe element on position 2 is: %d", ret4);
    } else {
        printf("\nPosition isn't valid.");
    }
    printf("\n\n");

    makeNullV1(&L1);
    makeNullV2(&L2);
    makeNullV3(&L3);
    makeNullV4(&L4);

    printf("Null all lists: \nList 1: ");
    printListV1(L1);
    printf("\nList 2: ");
    printListV2(L2);
    printf("\nList 3: ");
    printListV3(L3);
    printf("\nList 4: ");
    printListV4(L4);
    
    //FREE SA ALLOCATED MEMORY
    free(L2);
    free(L3.elemPtr);  
}