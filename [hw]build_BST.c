#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct node{ 
    int data; 
    struct node *left, *right; 
}Node;

void inorder(Node* root){
	if(root)
	{
		inorder(root->left);
		printf(" %d",root->data);
		inorder(root->right);
	}   
}

int countnonleaf(Node* node){
	if(node->left||node->right)
	{
		int left = countnonleaf(node->left);
		int right = countnonleaf(node->right);
		return left + right + 1;	
	}
	return 0;  
}

int countleaf(Node* node){
	 
	if(node->left||node->right)
	{
		int left = countleaf(node->left);
		int right = countleaf(node->right);
		return left + right;	
	}
	return 1; 
}

int height(Node* node){
   
   if(node)
   {
		int left = height(node->left);
		int right = height(node->right);
		return left > right ? left+1:right+1;
   }
   return 0;
}

int is_BST(Node* node){  

	int left=1,right=1;
	
	if(!node->left && !node->right)
	{
		return 1;
	}
	
	if(node->left)
	{
		left = node->left->data < node->data && is_BST(node->left);
	}
	
	if(node->right)
	{
		right = node->right->data > node->data && is_BST(node->right);
	}
	
	return left && right;

}

Node* insert(Node* node, int data){ 
    
	if(!node)
	{
		node = (Node*)malloc(sizeof(Node));
		node->data = data;
		node->left = node->right = NULL;	
	}
	else if(data<node->data)
	{
		node->left = insert(node->left,data);
	}
	else if(data>node->data)
	{
		node->right = insert(node->right,data);
	}
	else //¤w¦s¦b 
	{
		return NULL;
	}
	
	return node;
	
}

int main(){
    int insert_data[] = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
	Node* root = NULL; 
	int i;
    root = insert(root, insert_data[0]);
	int len = sizeof(insert_data)/sizeof(insert_data[0]); 
    for(i=1;i<len;i++){
    	insert(root, insert_data[i]);
	}
	printf("inorder traversal: ");
    inorder(root);
    printf("\nIs it a Binary Search Tree(BST)?: ");
    printf(is_BST(root)==1 ? "Yes" : "No");
	printf("\nroot data: %d\n",root->data);
	printf("the number of leaves: %d\n",countleaf(root));
	printf("the number of non-leaves: %d\n",countnonleaf(root));
	printf("height: %d\n\n",height(root));
		
	root->data = 20;
	printf("Modify Binary Search Tree(BST): \n");
	printf("inorder traversal: ");
    inorder(root);
    printf("\nIs it a Binary Search Tree(BST)?: ");
    printf(is_BST(root)==1 ? "Yes" : "No");
    
    return 0; 
}
