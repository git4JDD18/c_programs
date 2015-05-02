#include<stdlib.h>
#include<stdio.h>

struct node
{
	struct node *left;
	struct node *right;
	int data;
};

struct node* treeInsert(struct node *root, int data);
int treeRemove(struct node *root, int data);
void inOrder(struct node *root);

int main()
{
	
	struct node *root = NULL, *myRoot1, *myRoot2;
	int myFlag = 0;
	
	root = treeInsert(root,10);
	root = treeInsert(root,30);
	root = treeInsert(root,20);
	root = treeInsert(root,50);
	root = treeInsert(root,66);
	myRoot1 = root;
	inOrder(myRoot1);
	
	myFlag = treeRemove(root,66);
	myRoot2 = root;
	if(myFlag == 0)
	{
		printf("node not found");
	}
	else
	{
		printf("node found and removed");
	}
	inOrder(myRoot2);
	
	return 0;
	
}
	

void inOrder(struct node *root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		printf("%d \n", root->data);
		fflush(stdout);
		inOrder(root->right);
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

int treeRemove(struct node *root, int data)
{
	struct node *current;
	current = root;
	int flag = 0;
	
	if(root == NULL)
	{
		printf("tree is empty, no node to remove \n");
		flag = 0;
	}
	else if(root->data == data)
	{
		flag = 1;
		free(root);
	}
	else
	{
		if(data < root->data)
		{
			treeRemove(root->left, data);
		}
		else
		{
			treeRemove(root->right, data);
		}
	}
	
	return flag;
}
