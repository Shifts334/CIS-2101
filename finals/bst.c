#include<stdio.h>
#include<stdlib.h>


#define MAX 15

typedef enum BOOL {FALSE, TRUE} Boolean;

//basic structre for a tree node 
typedef struct treeNode{
	int data;
	struct treeNode* left;
	struct treeNode* right;	
}treeType, *treePtr;

//prototypes
Boolean initialize(treePtr *root);
Boolean isMember(treePtr root, int elem);
void insertMember(treePtr *root, int elem);
void insertSet(treePtr *root, int arr[]);
void inorderDisplay(treePtr root);
void preorderDisplay(treePtr root);
void postorderDisplay(treePtr root);
void deleteMember(treePtr *root, int elem);




void main(){
	
}


Boolean initialize(treePtr *root){
	*root = NULL;
	return(*root==NULL)?TRUE:FALSE;
}

Boolean isMember(treePtr root, int elem){ // checks if whether item is a member
	while(root != NULL && root->data!= elem){
		root =(elem < root->data)? root->left : root->right;
	}
	return (root!= NULL) ? TRUE : FALSE;
}

void insertMember(treePtr *root, int elem){
	treePtr *trav = root, temp;
	
	if(isMember(*trav, elem)){
		
		temp = malloc(sizeof(treeType));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = elem;
		
		while(*trav != NULL){
			trav = (elem<(*trav)->data)? (*trav)->left : (*trav)->right;
		}
		*trav = temp;
		
	} else{
		
	}
	
}

void insertSet(treePtr *root, int arr[]){
	treePtr temp
}

















