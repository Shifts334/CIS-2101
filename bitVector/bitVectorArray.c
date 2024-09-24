#include<stdio.h>

#define size 10
typedef int set[size];

//prototypes
void insert(set A,int data);
void delete(set A, int data);
int isMember(set A, int data);
set* Union(set A, set B);
set* intersection(set A,set B);
set* difference(set A, set B);


int main(){
    set Array1={2,4,6,8};
    set Array2={1,3,5,7};
}

void insert(set A, int data){
    A[data]=1;
}

void delete(set A, int data){
    A[data]=0;
}

int isMember(set A, int data){
	return(A[data]==1)?1:0;
}

set* Union(set A, set B){
	set *C = malloc(sizeof(set));
	for(int i=0; i<size; i++){
		if(A[i]==1 || B[i]==1){
			*C[i]=1;
		}
		else{
			*C[i]=0;
		}
	}
	return C;
}

set* intersection(set A, set B){
	set *C = malloc(sizeof(set));
	for(int i=0; i<size; i++){
		if(A[i]==1 && B[i]==1){
			*C[i]=1;
		}
		else{
			*C[i]=0;
		}
	}

	return C;
}

set* difference(set A, set B){
	set *C = malloc(sizeof(set));
	for(int i=0; i<size; i++){
		if(A[i]==1 && B[i]==0){
			*C[i]=1;
		}
		else{
			*C[i]=0;
		}
	}

	return C;
}

