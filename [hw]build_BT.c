#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct node{ 
    int data; 
    struct node *left, *right; 
}Node;

void postorder(Node* root){ 
	
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf(" %d",root->data);
	} 
} 

// record index of preorder[]
int preindex = 0; 

Node* build_binary_tree(int inorder[], int preorder[], int instart, int inend){	

	Node *N;
	if(instart<=inend)
	{
		N = (Node*)malloc(sizeof(Node));
		N->data = preorder[instart];
		
		int i = 0;
		while(preorder[instart] != inorder[i]) //§ä´M®Ú¸`ÂI 
		{
			++i;
		}
		
		N->left = build_binary_tree(inorder,preorder,instart+1,instart+i); // ¥ª¾ð½d³ò 
		N->right = build_binary_tree(inorder+i+1,preorder,instart+i+1,inend); // ¥k¾ð½d³ò 
		
		return N;
	}	
	return NULL;
}

int main(){
	
	int tree1preorder[] = {4,2,1,3,6,5,7};
	int tree1inorder[] = {1,2,3,4,5,6,7};
	
	int len1 = sizeof(tree1inorder)/sizeof(tree1inorder[0]);
	Node *root1 =  build_binary_tree(tree1inorder, tree1preorder, 0, len1-1);
	
	printf("tree1 preorder traversal: 4 2 1 3 6 5 7 \n");
	printf("tree1 inorder traversal: 1 2 3 4 5 6 7 \n");
	printf("tree1 postorder traversal: ");
    postorder(root1);
    preindex = 0;
    
    int tree2inorder[] = {5,9,3,8,4,7,6};
	int tree2preorder[] = {8,9,5,3,7,4,6};
	int len2 = sizeof(tree2inorder)/sizeof(tree2inorder[0]);
	Node *root2 =  build_binary_tree(tree2inorder, tree2preorder, 0, len2-1);
	
	printf("\n\ntree2 preorder traversal: 8 9 5 3 7 4 6 \n");
	printf("tree2 inorder traversal: 5 9 3 8 4 7 6 \n");
	printf("tree2 postorder traversal: ");
    postorder(root2);
    preindex = 0;
    
    return 0;
}
