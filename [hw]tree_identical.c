#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

typedef struct Node{
    struct Node *Lchild;
    int data;
    struct Node *Rchild;
}Node; 

Node* create(int data){
	struct Node *new_node;
	new_node = (Node* )malloc(sizeof(Node));
	new_node->Lchild = NULL;
	new_node->Rchild = NULL;
	new_node->data = data;
} 

int identical(Node *T1, Node *T2){
	
	if(!T1 && !T2)
		return 1;
	
	else if(!T1 || !T2)
		return 0;
			
	else
		return T1->data==T2->data && identical(T1->Lchild,T2->Lchild) &&  identical(T1->Rchild,T2->Rchild);
}

int search(Node *root,int search_val){
	
	if(root)
	{
		return root->data==search_val || search(root->Lchild,search_val) || search(root->Rchild,search_val);
	}
	
}

int main(){
	// tree
	struct Node *root;
	root = create(7);
    root->Lchild=create(43);
    root->Rchild=create(9);
    root->Lchild->Lchild=create(5);
    root->Lchild->Rchild=create(21);
    root->Rchild->Rchild=create(4);
    root->Lchild->Lchild->Lchild=create(13);
	// tree 1
	struct Node *root1;
	root1 = create(7);
    root1->Lchild=create(43);
    root1->Rchild=create(9);
    root1->Lchild->Lchild=create(5);
    root1->Lchild->Rchild=create(21);
    root1->Rchild->Rchild=create(4);
    root1->Lchild->Lchild->Lchild=create(13);
	// tree 2
	struct Node *root2;
	root2 = create(7);
    root2->Lchild=create(2);
    root2->Rchild=create(9);
    root2->Lchild->Lchild=create(5);
    root2->Lchild->Rchild=create(21);
    root2->Rchild->Lchild=create(0);
    root2->Rchild->Rchild=create(4);
    
    printf("Does tree and tree1 identical ?\n");
    printf(identical(root,root1)==1 ? "Yes" : "No");
    printf("\nDoes tree and tree2 identical ?\n");
    printf(identical(root,root2)==1 ? "Yes" : "No");
    
    printf("\nTree Search:");
	printf(" \nDoes 2 exist in tree1 ?\n");
	printf(search(root,2)==1 ? "Yes" : "No");
	printf(" \nDoes 2 exist tree2 ?\n");
	printf(search(root2,2)==1 ? "Yes" : "No");
    
/*   
tree
       7   
     /   \   
    43   9   
   /   \   \   
   5   21   4
  /
 13 
  
*/

/*   
tree1
       7   
     /   \   
    43   9   
   /   \   \   
   5   21   4
  /
 13 
   
*/

/*   
tree2
        7   
     /     \   
    2       9   
   /   \   / \   
   5   21 0   4
   
*/
}
