#include<stdlib.h>
#include<stdio.h>

struct node{
	
	struct node *right;
	struct node *left;
	int data;
};

struct node* treeInsert(struct node *root, int data);
void inorder(struct node *root);


int main()
{
	struct node *root = NULL, *myRoot;
	
	root = treeInsert(root,10);
	root = treeInsert(root,30);
	root = treeInsert(root,20);
	root = treeInsert(root,50);
	root = treeInsert(root,66);
	myRoot = root;
	inorder(myRoot);
	return 0;
	
}
	
void inorder(struct node *root) 
{
   if (root != NULL) 
   {
      inorder(root->left);
      printf("%d \n", root->data);
	  fflush(stdout);
      inorder(root->right);
   }
}

struct node* treeInsert(struct node *root, int data)
{
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right= NULL;
	
	if(root == NULL)
	{
		root = newNode;
	}
	else 
	{
		if(data < root->data)
		{
			root->left = treeInsert(root->left, data);
		}
		else
		{
			root->right = treeInsert(root->right, data);
		}
	}
	
	return root;
}
