#include<stdlib.h>
#include<stdio.h>

struct node{
	
	struct node *right;
	struct node *left;
	int data;
};

struct node* treeInsert(struct node *root, int data);
void inorder(struct node *root);
int treeDepth(struct node *root);

int main()
{
	struct node *root = NULL, *myRoot;
	int totalDepth = 0;
	
	root = treeInsert(root,10);
	root = treeInsert(root,30);
	root = treeInsert(root,20);
	root = treeInsert(root,50);
	root = treeInsert(root,66);
	myRoot = root;
	inorder(myRoot);
	totalDepth = treeDepth(root);
	printf("depth of tree is %d \n",totalDepth);
	return 0;
	
}
	
void inorder(struct node *root) 
{
	//int size = 0;
	if (root != NULL) 
	{
		inorder(root->left);
		//size = size+1;
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

int treeDepth(struct node *root)
{
	int depthLeft = 0, depthRight = 0, finalDepth = 0;
	
	if(root == NULL)
	{
		return 0;
	}
	depthLeft = depthLeft + treeDepth(root->left);
	printf("left depth : %d \n", depthLeft);
	fflush(stdout);
	depthRight = depthRight + treeDepth(root->right);
	printf("right depth : %d \n", depthRight);
	fflush(stdout);
	
	if(depthLeft > depthRight)
	{
		return (1+ depthLeft);
	}
	else
	{
		return (1+ depthRight);
	}
	
}

int isBalance(struct node *root)
{
	int flag = 0;
	
	if(root == NULL)
	{
		flag=1;
	}
	
}
