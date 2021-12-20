#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *Lchild;
    int data;
    struct Node *Rchild;
}Node; 

Node* create(int data){
	struct Node *new_node;
	new_node = (Node*)malloc(sizeof(new_node));
	new_node->Lchild = NULL;
	new_node->Rchild = NULL;
	new_node->data = data;
} 

void preorder(Node *root){
	
	if(root)
	{
		printf(" %d",root->data);
		preorder(root->Lchild);
		preorder(root->Rchild);
	}
}

void inorder(Node *root){
	
	if(root)
	{
		inorder(root->Lchild);
		printf(" %d",root->data);
		inorder(root->Rchild);
	}  
}

void postorder(Node *root){
	
	if(root)
	{
		postorder(root->Lchild);
		postorder(root->Rchild);
		printf(" %d",root->data);
	}  
}

int main(){
	// create tree
	struct Node *root;
	root = create(7);
    root->Lchild=create(43);
    root->Rchild=create(9);
    root->Lchild->Lchild=create(5);
    root->Lchild->Rchild=create(21);
    root->Rchild->Lchild=create(0);
    root->Rchild->Rchild=create(4);
    root->Lchild->Lchild->Lchild=create(13);
    
    
    
    // print answer
    printf("Preorder Traversal: ");
    preorder(root);
    
    printf("\nInorder Traversal: ");
    inorder(root);
    
    printf("\nPostorder Traversal: ");
    postorder(root);
}
