#include<stdio.h>
#include<stdlib.h>


//structure
typedef struct{
    int arr[10];
    int count;
}Sets;

//prototypes
int find(Sets *set, int num);
int isfull(Sets *set);
int isempty(Sets *set);
void display(Sets *set);
void insertSorted(Sets *set, int num);
void delete(Sets *set, int num);
void Union(Sets *set1, Sets *set2);
void intersection(Sets *set1, Sets *set2);
void difference();

//main function
int main()
{
    Sets set1 = {{1,2,3,4,5,6,7}, 7};
    Sets set2 = {{3,4,5,6,7,8,9}, 7};

}

//non main functions

int  isfull(Sets *set)
{
    if(set->count == 10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(Sets *set)
{
    if(set->count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int find(Sets *set, int num)
{
    int i;
    for(i=0; i<set->count; i++)
    {
        if(set->arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

void display(Sets *set)
{
    for(int i=0; i<set->count; i++)
    {
        printf("%d ", set->arr[i]);
    }
    printf("\n");
}

// main functions

void insertSorted(Sets *set , int num)
{
    if(isfull(set))
    {
        printf("Set is full\n");
    }
    else
    {
        for(int i=set->count; i!=0 && num>=set->arr[i]; i--)
        {
            set->arr[i] = set->arr[i-1];
        }
        set->arr[set->count] = num;
        set->count++;
    }
}

void delete(Sets *set, int num)
{
    int i = find(set, num);
    if(isempty(set))
    {
        printf("Set is empty\n");
    }
    else if(i == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        for (int j=i; j<set->count-1; j++)
        {
            set->arr[j] = set->arr[j+1];
        }
        set->count--;
    }
}

void Union(Sets *set1, Sets *set2)
{
    Sets set3 = {{}, 0};
    for(int i=0; i<set1->count; i++)
    {
        insertSorted(&set3, set1->arr[i]);
    }
    for(int i=0; i<set2->count; i++)
    {
        insertSorted(&set3, set2->arr[i]);
    }
    printf("Union: ");
    display(&set3);
}

void intersection(Sets *set1, Sets *set2)
{
    Sets set3 = {{}, 0};
    for(int i=0; i<set1->count; i++)
    {
        if(find(set2, set1->arr[i]) != -1)
        {
            insertSorted(&set3, set1->arr[i]);
        }
    }
    printf("Intersection: ");
    display(&set3);
}