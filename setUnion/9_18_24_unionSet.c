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
Sets Union(Sets set1, Sets set2);
Sets intersection(Sets set1, Sets set2);
Sets difference(Sets set1, Sets set2);

//main function
int main()
{
    Sets set1 = {{1,2,3,4,5,6,7}, 7};
    Sets set2 = {{3,4,5,6,7,8,9}, 7};
    Sets uniSet = Union(set1, set2);
    Sets interSet = intersection(set1, set2);
    Sets diffSet = difference(set1, set2);

    printf("Original Sets:\n");
    printf("Set1: ");
    display(&set1);
    printf("Set2: ");
    display(&set2);

    insertSorted(&set1, 8);
    printf("\nSet1 after inserting 8: ");
    display(&set1);
    insertSorted(&set2, 4);
    printf("Set2 after inserting 4: ");
    display(&set2);

    delete(&set1, 8);
    printf("\nSet1 after deleting 8: ");
    display(&set1);
    delete(&set2, 4);
    printf("Set2 after deleting 4: ");
    display(&set2);

    printf("\nUnion of Set1 and Set2: \n");
    display(&uniSet);
    printf("\nIntersection of Set1 and Set2: \n");
    display(&interSet);
    printf("\nDifference of Set1 and Set2: \n");
    display(&diffSet);

    return 0;


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
    if(set->count == -1)
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
	int i;
    for(i=0; i<set->count; i++)
    {
        printf("%d ", set->arr[i]);
    }
    printf("\n");
}

// main functions

void insertSorted(Sets *set , int num)
{
    int i;
    if(isfull(set))
    {
        printf("Set is full\n");
    }
    else
    {   //slight error with the for loop 2nd condition
        for(i=set->count; i!=0 && num<set->arr[i-1]; i--)
        {
            set->arr[i] = set->arr[i-1];
        }
        set->arr[i] = num;
        set->count++;
        // I didn't take into account the case of which index I would be inserting in.
    }
}

void delete(Sets *set, int num)
{
    int i = find(set, num);
    int j;
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
        for ( j=i; j<set->count-1; j++)
        {
            set->arr[j] = set->arr[j+1];
        }
        set->count--;
    }
}

Sets Union(Sets set1, Sets set2)
{
    Sets set3 = {{}, 0};
    int i;
    for( i=0; i<set1.count; i++)
    {
        insertSorted(&set3, set1.arr[i]);
    }
    for( i=0; i<set2.count; i++)
    {
        if(find(&set3, set2.arr[i]) == -1)
        {
            insertSorted(&set3, set2.arr[i]);
        }
    }
    return set3;
}

Sets intersection(Sets set1, Sets set2)
{
    Sets set3 = {{}, 0};
    int i;
    for( i=0; i<set1.count; i++)
    {
        if(find(&set2, set1.arr[i]) != -1)
        {
            insertSorted(&set3, set1.arr[i]);
        }
    }
    return set3;
}

Sets difference(Sets set1, Sets set2)
{
    Sets set3 = {{}, 0};
    int i;
    for( i=0; i<set1.count; i++)
    {
        if(find(&set2, set1.arr[i]) == -1)
        {
            insertSorted(&set3, set1.arr[i]);
        }
    }
    for(i=0; i<set2.count; i++)
    {
        if(find(&set1, set2.arr[i]) == -1)
        {
            insertSorted(&set3, set2.arr[i]);
        }
    }
    return set3;
}

